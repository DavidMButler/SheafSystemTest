
/**
 * Classname: G3DDescriptorsTabbedPane
 *
 * @author $Author: jebutler $
 *
 * @version $RCSfile: G3DDescriptorsTabbedPane.java,v $ $Revision: 1.7 $
 *
 * $Date: 2012/03/01 00:41:49 $
 *
 * Copyright (c) 2012 Limit Point Systems, Inc.
 */


package tools.viewer.user;

import tools.viewer.render.*;

import javax.swing.*;

/**
 *
 * 3D implementation of <code>DescriptorsTabbedPane</code> for
 * containing the script panels for the <code>Viewer</code>
 *
 */
public class G3DDescriptorsTabbedPane extends DescriptorsTabbedPane
{
  /**
   * The light list panel.
   */
  protected LightPanel lightPanel;

  /**
   * The camera list panel.
   */
  protected CameraPanel cameraPanel;

  /**
   * Default constructor
   */
  protected G3DDescriptorsTabbedPane(G3DViewer xviewer)
  {
    super(xviewer);

    lightPanel = new LightPanel(xviewer);
    add
      ("Lights", lightPanel);

    cameraPanel = new CameraPanel(xviewer);
    add
      ("Cameras", cameraPanel);
  }

  // DESCRIPTOR TABBED PANE FACET

  /**
   * Set the script edit mode
   */
  public void editScriptModeChanged()
  {
    super.editScriptModeChanged();

    lightPanel.editScriptModeChanged();
    cameraPanel.editScriptModeChanged();
  }

  /**
   * Set the enabled state of this <code>DescriptorsTabbedPane</code>
   * and the descriptor panels.
   */
  public void setEnabled(boolean xenabled)
  {
    super.setEnabled(xenabled);

    lightPanel.setEnabled(xenabled);
    cameraPanel.setEnabled(xenabled);
  }

  /**
   * Update the descriptor panels
   */
  public void update()
  {
    super.update();

    lightPanel.update();
    cameraPanel.update();
  }

  // G3D DESCRIPTOR TABBED PANE FACET

  /**
   * The selected light
   */
  public LightDescriptor getSelectedLight()
  {
    return lightPanel.getSelectedLight();
  }

  /**
   * The selected camera
   */
  public CameraDescriptor getSelectedCamera()
  {
    return cameraPanel.getSelectedCamera();
  }

  /**
   * Open the light properties dialog for the selected light
   */
  public void openSelectedLightProperties()
  {
    lightPanel.openSelectedProperties();
  }

  /**
   * Open the camera properties dialog for the selected camera
   */
  public void openSelectedCameraProperties()
  {
    cameraPanel.openSelectedProperties();
  }
}
