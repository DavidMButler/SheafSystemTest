
/**
 * Classname: ViewerAction
 *
 *
 *
 *
 * Copyright (c) 2013 Limit Point Systems, Inc.
 */


package tools.viewer.user;

import tools.common.gui.*;

/**
 *
 * Implementation of <code>GenericAction</code> which adds
 * a description for the status bar.
 *
 */
public class ViewerAction extends GenericAction
{
  /**
   * The action name.
   */
  protected String actionName;

  /**
   * The discription text.
   */
  protected String description;

  /**
   * The original enabled state during construction.
   */
  protected boolean originalEnabledState;

  /**
   * Constructor
   *
   */
  public ViewerAction(Object xtarget,
                      String xactionName,
                      String xmethodName,
                      String xlabelString,
                      String xdescription,
                      String xtoolTip,
                      String ximageFilePath,
                      String xacceleratorKeyString,
                      String xmnemonicString,
                      String xenabledString)
  {
    super(xtarget, xactionName, xmethodName, xlabelString, xtoolTip,
          ximageFilePath, xacceleratorKeyString, xmnemonicString,
          xenabledString);

    actionName = xactionName;
    description = xdescription;

    originalEnabledState = isEnabled();
  }

  /**
   * Constructor
   */
  public ViewerAction(Object target, String[] strings)
  {
    this(target, strings[0], strings[1], strings[2], strings[3],
         strings[4], strings[5], strings[6], strings[7], strings[8]);
  }

  /**
   * Accessor for the action name.
   *
   * @return The action name
   *
   */
  public String getActionName()
  {
    return actionName;
  }

  /**
   * Accessor for the description.
   *
   * @return The description
   *
   */
  public String getDescription()
  {
    return description;
  }

  /**
   * Accessor to the original action enabled state.
   *
   * @return The original enabled state
   *
   */
  public boolean getOriginalEnabledState()
  {
    return originalEnabledState;
  }

  /**
   * Set the enabled state to the original enabled state.
   */
  public void setToOriginalEnabledState()
  {
    setEnabled(originalEnabledState);
  }
}
