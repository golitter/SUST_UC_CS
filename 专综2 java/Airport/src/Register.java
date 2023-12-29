import jdk.nashorn.internal.scripts.JO;
import org.omg.CORBA.TIMEOUT;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class Register extends JFrame implements ActionListener {
    JLabel sysRegisterLa, userla, pwdla; // 系统注册 用户名 密码
    JButton registerBt, cancelBt; // 注册 取消
    JTextField userTxt;
    JPasswordField pwdTxt;
    public Register() {

        this.setTitle("注册界面");
        this.setLayout(null);
        this.setSize(400, 300);
        this.setLocation(800, 300);
        this.setResizable(false);
        this.init();
        this.setVisible(true);
    }
    private void init() {
        // 设置字体
        Font font = new Font("楷体", Font.BOLD, 20);
        // 系统注册
        sysRegisterLa = new JLabel("系统注册窗口");
        sysRegisterLa.setFont(font);
        sysRegisterLa.setSize(220, 40);
        sysRegisterLa.setLocation(100, 20);
        this.add(sysRegisterLa);

        // 用户名
        userla = new JLabel("用户名：");
        userla.setSize(200, 40);
        userla.setLocation(40, 60);
        this.add(userla);
        // 填写注册的用户名
        userTxt = new JTextField();
        userTxt.setSize(180, 26);
        userTxt.setLocation(100, 70);
        this.add(userTxt);

        // 密码
        pwdla = new JLabel("密码" +
                "：");
        pwdla.setSize(200, 40);
        pwdla.setLocation(40, 90);
        this.add(pwdla);
        // 填写注册的密码
        pwdTxt = new JPasswordField();
        pwdTxt.setSize(180, 26);
        pwdTxt.setLocation(100, 100);
        this.add(pwdTxt);

        // 按钮
        registerBt = new JButton("注册");
        registerBt.setSize(60, 25);
        registerBt.setLocation(80, 180);
        this.add(registerBt);
        cancelBt = new JButton("取消");
        cancelBt.setSize(60, 25);
        cancelBt.setLocation(200, 180);
        this.add(cancelBt);
        registerBt.addActionListener(this);
        cancelBt.addActionListener(this);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        JButton bt = (JButton) e.getSource();
        if(bt.getText().equals("注册")) {
            String name = userTxt.getText();
            String passwd = pwdTxt.getText();
            if(0 == name.length()) {
                JOptionPane.showMessageDialog(null, "账号不能为空");
                userTxt.grabFocus();
                return ;
            }
            if(0 == passwd.length()) {
                JOptionPane.showMessageDialog(null, "密码不能为空");
                pwdTxt.grabFocus();
                return ;
            }
            if(check(name, passwd) == false) {
                JOptionPane.showMessageDialog(null, "账号已存在");
                userTxt.grabFocus();
                return ;
            }
            JOptionPane.showMessageDialog(null, "注册成功");
//            Thread.sleep(1000);
//            System.exit(0);
        } else {
            this.dispose();
//            System.exit(0);
        }
    }
    private static boolean check(String name, String passwd) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        boolean result = false;
        try {
            String url = "jdbc:mysql://82.157.19.240:3306/airport_db?useSSL=false";
            String username = "root";
            String passwords = "mysql";
            Connection c = DriverManager.getConnection(url, username, passwords);
            if (c != null) {
                System.out.println("数据库连接成功!");
                PreparedStatement pst = c.prepareStatement("SELECT COUNT(*) FROM user_accounts WHERE username = ?");
                pst.setString(1, name);
                ResultSet resultSet = pst.executeQuery();
                resultSet.next();
                int count = resultSet.getInt(1);
                if (count > 0) {
                    System.out.println("账号名已存在，注册失败!");
                    return false; // 如果存在相同的用户名，返回false
                } else {
                    pst = c.prepareStatement("INSERT INTO user_accounts(username, password) VALUES (?, ?)");
                    pst.setString(1, name);
                    pst.setString(2, passwd);
                    result = pst.execute();
                    System.out.println("成功");
                }
            } else {
                System.out.println("数据库连接失败!");
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        return true;
    }
    public static void main(String[] args) {
        Register a = new Register();

    }
}