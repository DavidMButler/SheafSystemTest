/**
 *  Classname: KeyPressedEvent
 *
 *
 *
 *
 *  Copyright (c) 2013 Limit Point Systems, Inc.
 */

package tools.viewer.event;

import tools.viewer.render.*;

import java.awt.event.*;

/**
 *
 * Implementation <code>RenderThreadEvent</code> for
 * processing a key pressed event.
 *
 */
public class KeyPressedEvent extends RenderThreadEvent
{
  /**
   * The <code>KeyEvent</code>
   */
  protected KeyEvent keyEvent;

  /**
   * The constructor
   */
  public KeyPressedEvent(KeyEvent xkeyEvent)
  {
    keyEvent = xkeyEvent;
  }

  /**
   * Handle this <code>KeyPressedEvent</code>
   */
  public void handle(RenderThread xrenderThread)
  {
    if(abort)
      return;

    xrenderThread.keyPressed(keyEvent);
  }
}
