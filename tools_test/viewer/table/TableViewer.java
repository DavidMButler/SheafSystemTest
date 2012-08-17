
/**
 *  Classname: TableViewer
 *
 *  @author $Author: jebutler $
 *
 *  @version $RCSfile: TableViewer.java,v $ $Revision: 1.7 $
 *
 *  $Date: 2012/03/01 00:41:48 $
 *
 *  Copyright (c) 2012 Limit Point Systems, Inc.
 */


package tools.viewer.table;

import tools.common.gui.*;
import bindings.java.*;
import javax.swing.*;

/**
 * Viewer to display fields in table form.
 */
public class TableViewer extends LPSFrame
{
  /**
   * The <code>FieldTable</code>
   */
  protected FieldTable fieldTable;

  /**
   * Constructor
   */
  public TableViewer(FieldTableDescriptor xdescriptor)
  {
    super("Table Viewer");

    //     setDefaultLookAndFeelDecorated(true);

    fieldTable = new FieldTable(xdescriptor);
    getContentPane().add(fieldTable);

    pack();
    setVisible(true);

    setDefaultCloseOperation(DISPOSE_ON_CLOSE);
  }

  /**
   * Update the table
   */
  public void update()
  {
    fieldTable.update();
  }
}

