/**
 *  Classname: RenderEvent
 *
 *  @author $Author: jebutler $
 *
 *  @version $RCSfile: RenderEvent.java,v $ $Revision: 1.8 $
 *
 *  $Date: 2012/03/01 00:41:46 $
 *
 *  Copyright (c) 2012 Limit Point Systems, Inc.
 */

package tools.viewer.event;

import tools.viewer.render.*;

import java.awt.*;

/**
 *
 * Implementation <code>RenderThreadEvent</code> for
 * rendering a scene.
 *
 */
public class RenderEvent extends RenderThreadEvent
{
  /**
   * The <code>SceneDescriptor</code>
   */
  protected SceneDescriptor scene;

  /**
   * The reset view flag
   */
  protected boolean resetView;

  /**
   * The record mode
   */
  protected boolean recordMode;

  /**
   * The constructor
   */
  public RenderEvent(SceneDescriptor xscene,
                     boolean xresetView,
                     boolean xrecordMode)
  {
    scene = xscene;
    resetView = xresetView;
    recordMode = xrecordMode;
  }

  /**
   * Handle this <code>RenderEvent</code>
   */
  public void handle(RenderThread xrenderThread)
  {
    if(abort)
      return;

    setScreenCursor(xrenderThread, Cursor.WAIT_CURSOR);

    xrenderThread.copy(scene);

    if(abort)
    {
      setScreenCursor(xrenderThread, Cursor.DEFAULT_CURSOR);
      return;
    }

    xrenderThread.update();

    if(abort)
    {
      setScreenCursor(xrenderThread, Cursor.DEFAULT_CURSOR);
      return;
    }

    if(resetView)
      xrenderThread.resetView();

    if(abort)
    {
      setScreenCursor(xrenderThread, Cursor.DEFAULT_CURSOR);
      return;
    }

    if(recordMode)
      xrenderThread.record(scene.scene);
    else
      xrenderThread.render();

    setScreenCursor(xrenderThread, Cursor.DEFAULT_CURSOR);
  }
}
