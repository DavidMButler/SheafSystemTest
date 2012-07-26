/**
 * Classname: GuiUtilities
 *
 * @author $Author: jebutler $
 *
 * @version $RCSfile: GuiUtilities.java,v $ $Revision: 1.12 $
 *
 * $Date: 2012/03/01 00:41:43 $
 *
 * Copyright (c) 2012 Limit Point Systems, Inc.
 */

package tools.common.gui;

import tools.common.util.LPSDebug;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.net.URL;

/**
 * GuiUtilities provides static utility methods for
 * application gui support.
 * <p>
 */

public class GuiUtilities
{
  public static void setToExitOnClose(Frame frame)
  {
    frame.addWindowListener(new WindowAdapter()
                            {
                              public void windowClosing(WindowEvent e)
                              {
                                System.exit(0);
                              }
                            }
                           ); // Could be better!!!
  }

  public static Dimension getScreenSize()
  {
    return Toolkit.getDefaultToolkit().getScreenSize();
  }

  public static Dimension getScreenSize(Component c)
  {
    return c.getToolkit().getScreenSize();
  }

  public static void centerOnScreen(Component c)
  {
    Dimension screenSize = getScreenSize(c);
    Dimension size = c.getSize();
    int y = (screenSize.height - size.height) / 2;
    int x = (screenSize.width - size.width) / 2;
    c.setLocation(x, y);
  }

  public static void centerOnOwner(Dialog d)
  {
    Rectangle ownerBounds = d.getOwner().getBounds();
    Dimension size = d.getSize();
    int y = ownerBounds.y + ((ownerBounds.height - size.height) / 2);
    if(y < 0) y = 0;
    int x = ownerBounds.x + ((ownerBounds.width - size.width) / 2);
    if(x < 0) x = 0;
    d.setLocation(x, y);
  }

  public static ImageIcon getImageIcon(String fileName)
  {
    URL url = ClassLoader.getSystemResource(fileName);
    return getImageIcon(url);
  }

  public static ImageIcon getImageIcon(URL url)
  {
    ImageIcon icon = (url == null) ? null : (new ImageIcon(url));
    return icon;
  }

  public static ImageIcon getImageIcon(Object obj, String filePath)
  {
    URL url = obj.getClass().getResource(filePath);
    return getImageIcon(url);
  }

  public static Image getImage(String fileName)
  {
    ImageIcon icon = getImageIcon(fileName);
    return (icon != null) ? icon.getImage() : null;
  }

  public static Image getImage(URL url)
  {
    ImageIcon icon = getImageIcon(url);
    return (icon != null) ? icon.getImage() : null;
  }

  public static Image getImage(Object obj, String filePath)
  {
    URL url = obj.getClass().getResource(filePath);
    return getImage(url);
  }

  public static JLabel makeLabel(String text)
  {
    String labelText = " " + text + ": ";
    JLabel label = new JLabel(labelText, JLabel.RIGHT);
    return label;
  }

  public static JLabel makeLabel(String text, String toolTip)
  {
    JLabel label = makeLabel(text);
    label.setToolTipText(toolTip);
    return label;
  }
}


