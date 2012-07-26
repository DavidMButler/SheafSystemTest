/**
 * Classname: SheafScopeTabPane
 *
 * @author $Author: jebutler $
 *
 * @version $RCSfile: SheafScopeTabPane.java,v $ $Revision: 1.3 $
 *
 * $Date: 2012/03/01 00:41:41 $
 *
 * Copyright (c) 2012 Limit Point Systems, Inc.
 */

package tools.SheafScope;

import tools.common.gui.*;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.plaf.basic.BasicButtonUI;
import javax.swing.tree.*;
import javax.swing.event.*;

/**
 * A pane for displaying the tab on <code>SheafScopeDisplayPanel</code>
 */
public class SheafScopeTabPane extends JPanel
{
  protected SheafScopeDisplayPanel displayPanel;
  protected JLabel label;
  protected JButton deleteButton;

  /**
   * Constructor
   *
   * @param xdisplayPanel The tabbed panel.
   */
  public SheafScopeTabPane(SheafScopeDisplayPanel xdisplayPanel, String xname)
  {
    super(new FlowLayout(FlowLayout.LEFT, 0, 0));
    setOpaque(false);

    displayPanel = xdisplayPanel;

    label = new JLabel(xname);
    label.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 5));
    deleteButton = new TabButton();

    add(label);
    add(deleteButton);

//     Color color = displayPanel.createColor();
//     label.setBackground(color);
//     deleteButton.setBackground(color);
//     setBackground(color);

    setBorder(BorderFactory.createEmptyBorder(2, 2, 2, 2));
  }

  /**
   * The current index in the <code>SheafScopeDisplayPanel</code>
   */
  public int getIndex()
  {
    return displayPanel.indexOfTabComponent(this);
  }

  /**
   * Delete this tab.
   */
  public void deleteTab()
  {
    displayPanel.deleteTab(getIndex());
  }

  /**
   * Implemention of JButton for deleting the tab.
   */
  private class TabButton extends JButton implements ActionListener
  {
    /**
     * Default Constructor.
     */
    public TabButton()
    {
      int size = 17;
      setPreferredSize(new Dimension(size, size));
      setToolTipText("close this tab");

      // Make the button looks the same for all Laf's

      setUI(new BasicButtonUI());

      // Make it transparent

      setContentAreaFilled(false);

      // No need to be focusable

      setFocusable(false);
      setBorder(BorderFactory.createEtchedBorder());
      setBorderPainted(false);

      // Making nice rollover effect
      // we use the same listener for all buttons

      addMouseListener(buttonMouseListener);
      setRolloverEnabled(true);

      // Close the proper tab by clicking the button

      addActionListener(this);
    }

    /**
     * Process the event.
     */
    public void actionPerformed(ActionEvent e)
    {
      int index = getIndex();
      if(index != -1)
      {
        displayPanel.deleteTab(index);
      }
    }

    /**
     * Overwrite updateUI(): Do nothing.
     */
    public void updateUI()
    {
    }

    /**
     * Paint the cross.
     */
    protected void paintComponent(Graphics g)
    {
      super.paintComponent(g);
      Graphics2D g2 = (Graphics2D) g.create();

      // Shift the image for pressed buttons

      if(getModel().isPressed())
      {
        g2.translate(1, 1);
      }
      g2.setStroke(new BasicStroke(2));
      g2.setColor(Color.BLACK);
      if(getModel().isRollover())
      {
        g2.setColor(Color.MAGENTA);
      }
      int delta = 6;
      g2.drawLine(delta, delta, getWidth() - delta - 1, getHeight() - delta - 1);
      g2.drawLine(getWidth() - delta - 1, delta, delta, getHeight() - delta - 1);
      g2.dispose();
    }
  }

  /**
   * The delete button listener.
   */
  private final static MouseListener buttonMouseListener = new MouseAdapter()
  {
    public void mouseEntered(MouseEvent e)
    {
      Component component = e.getComponent();
      if(component instanceof AbstractButton)
      {
        AbstractButton button = (AbstractButton) component;
	button.setBorderPainted(true);
      }
    }

    public void mouseExited(MouseEvent e)
    {
      Component component = e.getComponent();
      if(component instanceof AbstractButton)
      {
        AbstractButton button = (AbstractButton) component;
	button.setBorderPainted(false);
      }
    }
  };  
}
