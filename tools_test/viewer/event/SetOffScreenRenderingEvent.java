/**
 *  Classname: SetOffScreenRenderingEvent
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
public class SetOffScreenRenderingEvent extends RenderThreadEvent
{
  /**
   * The off screen rendering mode
   */
  protected boolean mode;

  /**
   * The constructor
   */
  public SetOffScreenRenderingEvent(boolean xmode)
  {
    mode = xmode;
  }

  /**
   * Handle this <code>SetOffScreenRenderingEvent</code>
   */
  public void handle(RenderThread xrenderThread)
  {
    if(abort)
      return;

    if(mode)
      xrenderThread.render();

    if(abort)
      return;

    xrenderThread.setOffScreenRendering(mode);

    if(!mode)
      xrenderThread.render();
  }
}
