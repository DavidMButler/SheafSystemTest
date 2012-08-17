/**
 *  Classname: SheafScopeFieldActorDialog
 *
 *  @author $Author: jebutler $
 *
 *  @version $RCSfile: SheafScopeFieldActorDialog.java,v $ $Revision: 1.6 $
 *
 *  $Date: 2012/03/01 00:41:40 $
 *
 *  Copyright (c) 2012 Limit Point Systems, Inc.
 */

package tools.SheafScope;

import bindings.java.*;
import tools.common.gui.*;
import tools.viewer.application.*;

import java.awt.*;
import javax.swing.*;

/**
 * Implementation of <code>FieldActorDialog</code> for the
 * SheafScope.
 */
public class SheafScopeFieldActorDialog extends FieldActorDialog
{
  /**
   * The <code>FieldActorToolBar</code> representations.
   */
  protected static Class[] REPS = {PseudoColorFieldActorToolBar.class,
                                   GlyphFieldActorToolBar.class,
                                   HedgeHogFieldActorToolBar.class,
                                   TensorGlyphFieldActorToolBar.class,
                                   G2DFieldActorToolBar.class,
                                   FieldTableToolBar.class};

  /**
   * The constructor
   */
  public SheafScopeFieldActorDialog(SheafScopeFrame xframe)
  {
    super(xframe, xframe, REPS);
  }
}
