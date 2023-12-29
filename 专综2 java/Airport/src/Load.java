import jdk.nashorn.internal.scripts.JO;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class Load extends JFrame implements ActionListener {

    String url = "jdbc:mysql:jdbc:mysql://82.157.19.240:3306/airport_db";

    JLabel infola, userla, pwdla;
    Font f1, f2;
    JButton loginBt, cancelBt, signBt;
    JTextField userTxt;
    JPasswordField pwdTxt;
    public Load() {
        this.setTitle("登录");
        init();
        this.setSize(400, 300);
        this.setLocation(800, 300);
        this.setDefaultCloseOperation(1);
//        this.setResizable(false);

        this.setVisible(true);
    }
    public void init() {


        f1 = new Font("楷体", Font.BOLD, 20);
        f2 = new Font("楷体", Font.BOLD, 15);
        infola = new JLabel("机场信息管理系统");
        infola.setFont(f1);
        infola.setSize(220, 40);
        infola.setLocation(100, 20);
        this.add(infola);

        userla = new JLabel("用户名：");
        userla.setFont(f2);
        userla.setSize(200, 40);
        userla.setLocation(40, 60);
        this.add(userla);

        pwdla = new JLabel("密码：");
        pwdla.setFont(f2);
        pwdla.setSize(200, 40);
        pwdla.setLocation(40, 90);
        this.add(pwdla);

        loginBt = new JButton("登录");
        loginBt.setSize(100, 25);
        loginBt.setLocation(25, 180);
        this.add(loginBt);
        cancelBt = new JButton("取消");
        cancelBt.setSize(100, 25);
        cancelBt.setLocation(275, 180);
        this.add(cancelBt);
        signBt = new JButton("注册");
        signBt.setSize(100, 25);
        signBt.setLocation(150, 180);
        this.add(signBt);
        loginBt.addActionListener(this);
        cancelBt.addActionListener(this);
        signBt.addActionListener(this);

        userTxt = new JTextField();
        userTxt.setSize(180, 26);
        userTxt.setLocation(100, 70);
        this.add(userTxt);

        pwdTxt = new JPasswordField();
//        pwdTxt.setSize(180, 26);
//        pwdTxt.setLocation(100, 100);
//        this.add(pwdTxt);
        pwdTxt.setBounds(new Rectangle(100, 100, 180, 26));
        this.add(pwdTxt);
        JLabel lb = new JLabel("");
        this.add(lb);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        JButton bt = (JButton) e.getSource();
        if(bt.getText().equals("注册")) {
            new Register();
        } else if(bt.getText().equals("取消")) {
            System.exit(0);
        } else {
            // 登录
            String name = userTxt.getText();
            String passwd = pwdTxt.getText();
            if(name.length() == 0) {
                JOptionPane.showMessageDialog(null, "账号不能为空");
                userTxt.grabFocus();
                return ;
            }
            if(passwd.length() == 0) {
                JOptionPane.showMessageDialog(null, "密码不能为空");
                pwdTxt.grabFocus();
                return ;
            }
            if(check(name, passwd)) {
                JOptionPane.showMessageDialog(null, "登录成功");
//                new AirportDeal();
                new TableFrame();
                dispose();
            } else {
                JOptionPane.showMessageDialog(null, "账号或者密码错误");
            }
        }
    }
    public boolean check(String name, String password) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            return false;
        }

        boolean result = false;
        try {
            String url = "jdbc:mysql://82.157.19.240:3306/airport_db?useSSL=false"; // 注意设置时区，这个连接是8.0版本的mysql。
            String username = "root";
            String passwords = "mysql";
            Connection c = DriverManager.getConnection(url, username, passwords);
            if (c != null) {
                System.out.println("数据库连接成功!");
            } else {
                System.out.println("数据库连接失败!");
                return false;
            }

            PreparedStatement ps = c.prepareStatement("SELECT * FROM user_accounts WHERE username = ? AND password = ?");
            ps.setString(1, name);
            ps.setString(2, password);

            ResultSet rs = ps.executeQuery();
            if (rs.next()) {
                result = true;
            } else {
                System.out.println("账号或密码错误");
            }

            rs.close();
            ps.close();
            c.close();
        } catch (SQLException e2) {
            e2.printStackTrace();
        }
        return result;
    }

    public static void main(String[] args) {
        Load a = new Load();
    }
}
