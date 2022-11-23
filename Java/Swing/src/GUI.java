import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GUI implements ActionListener {
    JFrame frame = new JFrame("");
    JPanel panel = new JPanel();
    JPanel textPanel = new JPanel();
    JButton ok = new JButton("Ok");
    JButton cancel = new JButton("Cancel");
    JButton exit = new JButton("Exit");
    JTextArea textArea = new JTextArea(8,30);

    public void Load() {
        panel.add(ok);
        panel.add(cancel);
        panel.add(exit);
        frame.getContentPane().add(panel, BorderLayout.SOUTH);
        textPanel.add(textArea);
        frame.getContentPane().add(textPanel, BorderLayout.CENTER);
        frame.setSize(300,200);
        frame.setVisible(true);
        ok.addActionListener(this);
        cancel.addActionListener(this);
        exit.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        JButton jButton = (JButton) e.getSource();
        if(jButton == ok) {
            textArea.setText("Ok is pressed");
        }
        else if(jButton == cancel) {
            textArea.setText("Cancel is pressed");
        }
        else if(jButton == exit) {
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        GUI gui = new GUI();
        gui.Load();
    }
}
