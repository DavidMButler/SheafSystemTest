
/**
 * Classname: GlyphFieldActor
 *
 *
 *
 *
 * Copyright (c) 2013 Limit Point Systems, Inc.
 */


package tools.viewer.render;

import tools.viewer.common.*;
import tools.viewer.user.*;
import bindings.java.*;

import java.awt.*;
import java.util.*;
import vtk.*;

/**
 *
 * Implementation of <code>G3DFieldActor</code> for a 3 dimensional graphic
 * representation with <code>vtkGlyph3D</code>
 *
 */
public class GlyphFieldActor extends G3DFieldActor
{
  // SHEAF FACET

  /**
   * The scalar property section
   */
  protected sec_vd scalarProperty = null;

  /**
   * The vector property section
   */
  protected sec_vd vectorProperty = null;

  //
  // The Filters
  //

  /**
   * The <code>vtkGlyph3D</code>
   */
  protected vtkGlyph3D glyph = null;

  // CONSTRUTORS

  /**
   * Default constructor
   */
  public GlyphFieldActor()
  {}

  /**
   * Constructor
   *
   * @param xcoordinates The coordinates section
   * @param xscalarProperty The scalar property section
   * @param xvectorProperty The vector property section
   * @param xlookupTable The VTK lookup table
   */
  public GlyphFieldActor(sec_vd xcoordinates,
                         sec_vd xscalarProperty,
                         sec_vd xvectorProperty,
                         LookupTable xlookupTable)
  {
    super(xcoordinates, xlookupTable);

    scalarProperty = xscalarProperty;
    vectorProperty = xvectorProperty;

    init();
  }

  /**
   * Initialize this <code>GlyphFieldActor</code>
   */
  protected void init()
  {
    super.init();

    createGlyph();
  }

  /**
   * Create the glph
   */
  protected void createGlyph()
  {
    // Create the glyph

    glyph = new vtkGlyph3D();

    // Hook the glyph up to the data flow

    glyph.SetInput(mapperInput);
    gridMapper.SetInput(glyph.GetOutput());
  }

  /**
   * The list of psuedo color properties
   */
  public sec_vd[] getProperties()
  {
    int ct = 0;
    if(scalarProperty != null)
      ct++;
    if(vectorProperty != null)
      ct++;

    sec_vd[] result = new sec_vd[ct];

    ct = 0;
    if(scalarProperty != null)
    {
      result[ct] = scalarProperty;
      ct++;
    }
    if(vectorProperty != null)
    {
      result[ct] = vectorProperty;
    }

    return result;
  }
}
