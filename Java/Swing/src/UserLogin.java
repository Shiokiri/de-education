import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UserLogin implements ActionListener {
    JFrame frame = new JFrame("用户登录");
    JPanel panel = new JPanel();
    JPanel textPanel = new JPanel();
    JButton login = new JButton("登陆");
    JButton exit = new JButton("退出");
    JLabel userAccount = new JLabel("用户名：");
    JLabel userPassword = new JLabel("密码：");
    JTextField accountText = new JTextField(10);
    JPasswordField passwordField = new JPasswordField(10);

    public void Load() {
        panel.add(login);
        panel.add(exit);
        frame.getContentPane().add(panel, BorderLayout.SOUTH);
        textPanel.add(userAccount);
        textPanel.add(accountText);
        textPanel.add(userPassword);
        textPanel.add(passwordField);
        frame.getContentPane().add(textPanel, BorderLayout.NORTH);
        frame.setSize(350,150);
        frame.setVisible(true);
        login.addActionListener(this);
        exit.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        JButton jButton = (JButton) e.getSource();
        if(jButton == login) {
            JOptionPane.showMessageDialog(frame, "Welcome to admin", "登陆成功", JOptionPane.INFORMATION_MESSAGE);
        }
        else if(jButton == exit) {
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        UserLogin userLogin = new UserLogin();
        userLogin.Load();
    }
}
