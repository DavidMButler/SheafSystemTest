
/**
 * Classname: SheafScopePosetTableModel
 *
 * @author $Author: jebutler $
 *
 * @version $RCSfile: SheafScopePosetTableModel.java,v $ $Revision: 1.22 $
 *
 * $Date: 2012/03/01 00:41:40 $
 *
 * Copyright (c) 2012 Limit Point Systems, Inc.
 */

package tools.SheafScope;

import bindings.java.*;
import tools.common.util.*;

import javax.swing.table.*;
import java.util.*;

/**
 *
 * Extends <code>SheafScopeAbstractTableModel</code> to provide
 * poset specific table model functionality.<p>
 */
public class SheafScopePosetTableModel extends SheafScopeAbstractTableModel
{

  /**
   * Constructor<p>
   *
   */
  public SheafScopePosetTableModel()
  {
    super();
  }

  /**
   * Instantiates a new <code>SheafScopePosetTableModel</code> based on the down set
   * of <code>PosetMember</code> <i>member</i>.<p>
   *
   * @param xmember The <code>abstract_poset_member</code> this model will be based on.
   */
  public SheafScopePosetTableModel(abstract_poset_member xmember)
  {
    this();
    this.member = xmember;

    setColumnNames();

    try
    {
      // Initialize filter to subposet whole.

      filter = new subposet(xmember.host(), xmember.host().name());
    }
    catch(Exception ex)
    {
      // $$HACK: Need better error handling.

      ex.printStackTrace();
    }
  }

  /**
   * Public refresh method for this model.
   *
   * @param xitr An iterator over this dataset's displayed (tree) nodes.
   * @param xsubposetName The name of the subposet filter for this model.
   *
   * 
   */
  public void refresh(Enumeration xitr, String xsubposetName)
  {
    try
    {
      filter.attach_to_state(member.host(), xsubposetName);
    }
    catch(Exception ex)
    {
      // $$HACK: Need better error handling.

      ex.printStackTrace();
    }

    refresh(xitr, filter);
  }

  /**
   * Public refresh method for this model.
   *
   * @param xitr An iterator over this dataset's displayed (tree) nodes.
   * @param xfilter The subposet filter for this model.
   *
   * 
   */
  protected void refresh(Enumeration xitr, subposet xfilter)
  {
    try
    {
      // Clear the arraylist containing the displayed.

      rowMembers.clear();
      displayedMembers.clear();

      while(xitr.hasMoreElements())
      {
        SheafScopeTreeNode node = (SheafScopeTreeNode)xitr.nextElement();

        abstract_poset_member mbr = node.getMember();

        scoped_index index = mbr.index();

        if(xfilter.contains_member(index))
        {
          Long mbrIndex = new Long(index.pod());

          if(!displayedMembers.contains(mbrIndex))
          {
            displayedMembers.add(mbrIndex);

            refreshRow(mbr);

            rowMembers.add(mbr);
          }
        }
      }
    }
    catch(Exception ex)
    {
      // $$HACK: Need better error handling.

      ex.printStackTrace();
    }
  }


  /**
   * Refreshes the row associated with <i>srsMember</i><p>
   *
   * @param rowMember The <code>abstract_poset_member</code> identifying
   * the table row to be refreshed.
   *
   * 
   */
  protected void refreshRow(abstract_poset_member rowMember)
  {
    try
    {
      String name = rowMember.name();

      if("bottom".equals(name) && !showBottoms)
        return;

      // Create a vector for the row info.

      Vector<Object> mbrData = new Vector<Object>();
      //Vector mbrData = new Vector();

      poset_dof_iterator mbrDofItr = null;
      poset_dof_map dofMap = null;

      if(!dofDisplay.equals(SheafScopeApplication.DISPLAY_NO_DOFS))
      {
        schema_poset_member schemaMember = rowMember.schema();

        int currentMemberVersion = standard_version_index.CURRENT_MEMBER_VERSION.swigValue();
        mbrDofItr = schemaMember.row_dof_iterator(currentMemberVersion);
      }

      // Add the name.

      mbrData.add(name);

      // Convert the "int" return value of index() to a String.

      String index = Integer.toString(rowMember.index().pod());

      // Add the index.

      mbrData.add(index);

      // Add other id space indices.

      index_map idMap;

      for(int i=0; i<idSpaces.size(); i++)
      {
        String spaceName = idSpaces.elementAt(i);
        idMap = rowMember.host().id_space(spaceName).id_map();

        index = Integer.toString(idMap.domain_id(rowMember.index()));

        mbrData.add(index);
      }

      // Is a jim or jrm?

      if(rowMember.is_jim(false))
      {
        mbrData.add("jim");

        if(!dofDisplay.equals(SheafScopeApplication.DISPLAY_NO_DOFS))
        {
          dofMap = rowMember.dof_map(false);

          int ct=0;

          while(!mbrDofItr.is_done())
          {
            schema_poset_member item = mbrDofItr.item();

            // Get the value of the dof.

            String valueString =
              SheafUtilities.getDofAsString(dofMap, item);

            mbrData.add(valueString);
            mbrDofItr.next();

            ct++;
            if(dofDisplay.equals(SheafScopeApplication.DISPLAY_LIMITED_DOFS) &&
                ct >= dofLimit)
              break;
          }
        }
      }
      else // Member is a jrm -- no dof data.
      {
        if(!dofDisplay.equals(SheafScopeApplication.DISPLAY_NO_DOFS))
        {
          int ct=0;

          mbrData.add("jrm");

          while(!mbrDofItr.is_done())
          {
            mbrData.add("");
            mbrDofItr.next();

            ct++;
            if(dofDisplay.equals(SheafScopeApplication.DISPLAY_LIMITED_DOFS) &&
                ct >= dofLimit)
              break;
          }
        }
      }

      // Add the row.

      addRow(mbrData);
    }
    catch(Exception ex)
    {
      // $$HACK: Need better error handling.

      ex.printStackTrace();
    }
  }
}


























