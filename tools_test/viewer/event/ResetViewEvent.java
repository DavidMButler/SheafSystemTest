/**
 *  Classname: ResetViewEvent
 *
 *
 *
 *
 *  Copyright (c) 2013 Limit Point Systems, Inc.
 */

package tools.viewer.event;

import tools.viewer.render.*;

/**
 *
 * Implementation <code>RenderThreadEvent</code> for
 * resetting the view.
 *
 */
public class ResetViewEvent extends RenderThreadEvent
{
  /**
   * The constructor
   */
  public ResetViewEvent()
  {}

  /**
   * Handle this <code>ResetViewEvent</code>
   */
  public void handle(RenderThread xrenderThread)
  {
    if(abort)
      return;

    xrenderThread.resetView();

    if(abort)
      return;

    xrenderThread.render();
  }
}
