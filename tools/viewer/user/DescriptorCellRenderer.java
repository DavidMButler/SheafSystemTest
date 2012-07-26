/**
 * Classname: DescriptorCellRenderer
 *
 * @author $Author: jebutler $
 *
 * @version $RCSfile: DescriptorCellRenderer.java,v $ $Revision: 1.6 $
 *
 * $Date: 2012/03/01 00:41:48 $
 *
 * Copyright (c) 2012 Limit Point Systems, Inc.
 */


package tools.viewer.user;

import tools.viewer.render.*;

import javax.swing.*;
import java.awt.*;

public class DescriptorCellRenderer extends JLabel implements ListCellRenderer
{
  // Default values.

  static final Color DEFAULT_FOREGROUND  = Color.black;
  static final Color SELECTED_FOREGROUND = Color.red;

  /**
   * Constructor
   */
  public DescriptorCellRenderer()
  {
    super();
  }

  public Component getListCellRendererComponent(JList list,
      Object value,
      int index,
      boolean isSelected,
      boolean cellHasFocus)
  {
    String s = value.toString();
    setText(s);

    Descriptor descriptor = (Descriptor) value;

    if(descriptor.selected)
      setForeground(SELECTED_FOREGROUND);
    else
      setForeground(DEFAULT_FOREGROUND);

    if(isSelected)
      setBackground(list.getSelectionBackground());
    else
      setBackground(list.getBackground());

    setEnabled(list.isEnabled());
    setFont(list.getFont());
    setOpaque(true);
    return this;
  }
}
