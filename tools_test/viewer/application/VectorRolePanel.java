/**
 *  Classname: VectorRolePanel
 *
 *  @author $Author: jebutler $
 *
 *  @version $RCSfile: VectorRolePanel.java,v $ $Revision: 1.6 $
 *
 *  $Date: 2012/03/01 00:41:44 $
 *
 *  Copyright (c) 2012 Limit Point Systems, Inc.
 */

package tools.viewer.application;

import bindings.java.*;

import javax.swing.*;

/**
 * Implementation of <code>RolePanel</code> for a vector section.
 */
public class VectorRolePanel extends RolePanel
{
  /**
   * The constructor
   */
  public VectorRolePanel()
  {
    super();
  }

  /**
   * Return the role text
   */
  protected String getRole()
  {
    return "Vector Property Section";
  }

  /**
   * True, if the role can be filled by xsection
   */
  protected boolean canFillRole(sec_vd xsection)
  {
    try
    {
      int df = xsection.df();

      if(df == 3)
        return true;
    }
    catch(Exception e)
    {
      // $$HACK: Need better error handling.

      e.printStackTrace();
    }

    return false;
  }
}
