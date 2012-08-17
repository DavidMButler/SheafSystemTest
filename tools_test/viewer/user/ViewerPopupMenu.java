
/**
 * Classname: ViewerPopupMenu
 *
 * @author $Author: jebutler $
 *
 * @version $RCSfile: ViewerPopupMenu.java,v $ $Revision: 1.6 $
 *
 * $Date: 2012/03/01 00:41:49 $
 *
 * Copyright (c) 2012 Limit Point Systems, Inc.
 */


package tools.viewer.user;

import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import tools.viewer.common.*;
import tools.common.gui.*;

/**
 *
 * Specialization of <code>JPopupMenu</code> for tool bars which interact
 * with the <code>Viewer</code>
 *
 */
public class ViewerPopupMenu extends JPopupMenu
{
  /**
   * The <code>Viewer</code>
   */
  protected Viewer viewer;

  /**
   * Constructor
   *
   */
  public ViewerPopupMenu(Viewer xviewer, String xtitle)
  {
    super(xtitle);

    viewer = xviewer;
  }

  /**
   * Add a <code>ViewerAction</code>
   */
  public JMenuItem add
    (ViewerAction action)
  {
    // Add the viewer action mouse listener to the resulting button.

    JMenuItem result = super.add(action);
    result.addMouseListener(new ViewerActionMouseAdapter(action,
                            viewer));

    return result;
  }
}
