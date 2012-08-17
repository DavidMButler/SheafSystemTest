
/**
 * Classname: Actions
 *
 * @author $Author: jebutler $
 *
 * @version $RCSfile: Actions.java,v $ $Revision: 1.9 $
 *
 * $Date: 2012/03/01 00:41:42 $
 *
 * Copyright (c) 2012 Limit Point Systems, Inc.
 */

package tools.common.gui;

import java.awt.event.*;
import java.util.*;
import javax.swing.*;

//$$TODO: Provide betted documentation.

// Note: An "actionSpec" is an array of Strings which contains the following:
//
//   0. action name
//   1. action method
//   2. action label
//   3. tooltip text
//   4. icon path
//   5. accelerator key
//   6. mnemonic
//   7. is enabled: "true" or "false"

/**
 *  Class to provide a container and factory for actions.
 */
public class Actions
{
  protected HashMap<String, AbstractAction> actionMap =
    new HashMap<String, AbstractAction>();

  /**
   * Constructor
   */
  public Actions()
  {}

  /**
   * Constructor
   */
  public Actions(Object target, String[][] actionSpecs)
  {
    create(target, actionSpecs);
  }

  /**
   * Create actions from an array of action specifications
   * and stores them for later access in this container.
   */
  public void create(Object target, String[][] actionSpecs)
  {
    for(int i=0; i<actionSpecs.length; ++i)
    {
      put(actionSpecs[i][0], new GenericAction(target, actionSpecs[i]));
    }
  }

  /**
   * Create actions from an action specification
   * and stores it for later access in this container.
   */
  public void create(Object target, String[] actionSpec)
  {
    put(actionSpec[0], new GenericAction(target, actionSpec));
  }

  /**
   * Create actions from an action specification
   * and stores it for later access in this container.
   */
  public  void create(Object target,
                      String actionName,
                      String methodName,
                      String labelString,
                      String toolTip,
                      String imageFilePath,
                      String acceleratorKeyString,
                      String mnemonicString,
                      String enabledString)
  {
    put(actionName,
        new GenericAction(target,
                          actionName,
                          methodName,
                          labelString,
                          toolTip,
                          imageFilePath,
                          acceleratorKeyString,
                          mnemonicString,
                          enabledString));
  }

  /**
   * Put an action into this container.
   */
  public void put(String actionName, AbstractAction action)
  {
    actionMap.put(actionName, action);
  }

  /**
   * Get an action by name.
   */
  public AbstractAction get
    (String actionName)
  {
    return actionMap.get(actionName);
  }

  /**
   * Get the name keys
   */
  public Set<String> names()
  {
    return actionMap.keySet();
  }
}
