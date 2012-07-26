/**
 *  Classname: OpenMovieEvent
 *
 *  @author $Author: jebutler $
 *
 *  @version $RCSfile: OpenMovieEvent.java,v $ $Revision: 1.5 $
 *
 *  $Date: 2012/03/01 00:41:46 $
 *
 *  Copyright (c) 2012 Limit Point Systems, Inc.
 */

package tools.viewer.event;

import tools.viewer.user.*;

import java.io.*;

/**
 *
 * Implementation <code>ViewerEvent</code> for opening a movie file.
 *
 */
public class OpenMovieEvent extends ViewerEvent
{
  /**
   * The file
   */
  protected File file;

  /**
   * The constructor
   */
  public OpenMovieEvent(File xfile)
  {
    file = xfile;
  }

  /**
   * Handle this <code>OpenMovieEvent</code>
   */
  public void handle(Viewer xviewer)
  {
    if(abort)
      return;

    xviewer.openMovie(file);
  }
}
