/**
 * Classname: GlyphFieldActorPropertiesPanel
 *
 * @author $Author: jebutler $
 *
 * @version $RCSfile: GlyphFieldActorPropertiesPanel.java,v $ $Revision: 1.7 $
 *
 * $Date: 2012/03/01 00:41:49 $
 *
 * Copyright (c) 2012 Limit Point Systems, Inc.
 */

package tools.viewer.user;

import tools.viewer.common.*;
import tools.viewer.render.*;
import tools.common.gui.*;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.border.*;
import java.text.*;
import vtk.*;

/**
 * Implementation of <code>G3DFieldActorPropertiesPanel</code> for editing the
 * values of a <code>GlyphFieldActorDescriptor</code>.
 */
public class GlyphFieldActorPropertiesPanel
      extends G3DFieldActorPropertiesPanel
{
  // CONSTANTS FACET

  protected static final String[] SCALE_MODES =
    { ViewerConstants.SCALAR,
      ViewerConstants.VECTOR_MAGNITUDE,
      ViewerConstants.VECTOR_COMPONENTS };

  protected static final String[] COLOR_MODES =
    { ViewerConstants.SCALAR,
      ViewerConstants.VECTOR_MAGNITUDE };

  // GUI FACET

  protected JPanel glyphPanel;

  protected JComboBox sourceComboBox;
  protected JSpinner scaleFactorSpinner;
  protected JComboBox scaleModeComboBox;
  protected JComboBox colorModeComboBox;

  // CONSTRUCTORS

  /**
   * Constructor
   */
  public GlyphFieldActorPropertiesPanel(G3DViewer xviewer,
                                        FieldActorDescriptor[] xdescriptors)
  {
    super(xviewer, xdescriptors);

    glyphPanel = createGlyphPanel();

    tabbedPane.addTab("Glyph", glyphPanel);

    initValues();
  }

  // CREATE FACET

  /**
   * Create glyph panel
   */
  protected JPanel createGlyphPanel()
  {
    JPanel result = new JPanel();
    result.setBorder(
      BorderFactory.createCompoundBorder(
        BorderFactory.createEmptyBorder(6, 12, 6, 12),
        BorderFactory.createTitledBorder("Glyph:")));

    result.setLayout(new BorderLayout());

    JPanel mainPanel = new JPanel();
    GridLayout layout = new GridLayout(4,2);
    layout.setVgap(48);
    layout.setHgap(6);
    mainPanel.setLayout(layout);

    result.add(Box.createVerticalStrut(12), BorderLayout.NORTH);
    result.add(Box.createVerticalStrut(12), BorderLayout.SOUTH);
    result.add(Box.createHorizontalStrut(12), BorderLayout.EAST);
    result.add(Box.createHorizontalStrut(12), BorderLayout.WEST);
    result.add(mainPanel, BorderLayout.CENTER);

    //=====

    JLabel sourceLabel = new JLabel("Source:", JLabel.RIGHT);
    sourceLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

    sourceComboBox = new JComboBox(ViewerConstants.SOURCES);

    mainPanel.add(sourceLabel);
    mainPanel.add(sourceComboBox);

    //=====

    JLabel scaleFactorLabel = new JLabel("Scale Factor: ", JLabel.RIGHT);
    scaleFactorLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

    SpinnerModel scaleFactorModel = new SpinnerNumberModel(1.0, 0.0,
                                    10000.0, 0.01);

    scaleFactorSpinner = new JSpinner(scaleFactorModel);

    mainPanel.add(scaleFactorLabel);
    mainPanel.add(scaleFactorSpinner);

    //=====

    JLabel scaleModeLabel = new JLabel("Scale By:", JLabel.RIGHT);
    scaleModeLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

    scaleModeComboBox = new JComboBox(SCALE_MODES);

    mainPanel.add(scaleModeLabel);
    mainPanel.add(scaleModeComboBox);

    //=====

    JLabel colorModeLabel = new JLabel("Color By:", JLabel.RIGHT);
    colorModeLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

    colorModeComboBox = new JComboBox(COLOR_MODES);

    mainPanel.add(colorModeLabel);
    mainPanel.add(colorModeComboBox);

    //=====

    return result;
  }

  // INITIALIZE FACET

  /**
   *
   */
  public void initValues()
  {
    super.initValues();

    // Use the first actor in the list to initialize the
    // user interface.

    GlyphFieldActorDescriptor actor = (GlyphFieldActorDescriptor) descriptors[0];

    initGlyphPanel(actor);
  }

  /**
   *
   */
  protected void initGlyphPanel(GlyphFieldActorDescriptor actor)
  {
    sourceComboBox.setSelectedItem(actor.source);
    scaleFactorSpinner.setValue(actor.scaleFactor);
    scaleModeComboBox.setSelectedItem(actor.scaleMode);
    colorModeComboBox.setSelectedItem(actor.colorMode);
  }

  // APPLY FACET

  /**
   *
   */
  public void doApply()
  {
    // Set the wait state to true, it is restored by
    // UpdatePropertiesPanelEvent.

    setWaitState(true);

    synchronized (viewer.getScript())
    {
      synchronized (viewer.getScene())
      {
        // Apply the changed to the actors

        GlyphFieldActorDescriptor actor;

        for(int i=0; i<descriptors.length; i++)
        {
          actor = (GlyphFieldActorDescriptor) descriptors[i];

          applyGlyph(actor);
        }
      }
    }

    super.doApply(false);
  }

  /**
   *
   */
  public void applyGlyph(GlyphFieldActorDescriptor actor)
  {
    actor.source = (String) sourceComboBox.getSelectedItem();
    actor.scaleFactor = ((SpinnerNumberModel)scaleFactorSpinner.getModel()).getNumber().doubleValue();
    actor.scaleMode = (String) scaleModeComboBox.getSelectedItem();
    actor.colorMode = (String) colorModeComboBox.getSelectedItem();
  }
}
