/**
 *  Classname: SetAnimationSceneEvent
 *
 *
 *
 *
 *  Copyright (c) 2013 Limit Point Systems, Inc.
 */

package tools.viewer.event;

import tools.viewer.user.*;
import tools.viewer.render.*;

/**
 *
 * Implementation <code>ViewerEvent</code> for setting the animation
 * <code>SceneDescriptor</code>
 *
 */
public class SetAnimationSceneEvent extends ViewerEvent
{
  /**
   * The scene
   */
  protected SceneDescriptor scene;

  /**
   * The constructor
   */
  public SetAnimationSceneEvent(SceneDescriptor xscene)
  {
    scene = xscene;
  }

  /**
   * Handle this <code>SetAnimationSceneEvent</code>
   */
  public void handle(Viewer xviewer)
  {
    if(abort)
      return;

    xviewer.setAnimationScene(scene);
  }
}
