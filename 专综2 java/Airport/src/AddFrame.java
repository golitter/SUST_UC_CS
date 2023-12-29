import javafx.scene.control.Tab;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class AddFrame extends JFrame implements ActionListener {
    JLabel idla, namela, addressla, typela, phonela, levella;
    JTextField idTxt, nameTxt, addressTxt, typeTxt, phoneTxt, levelTxt;
    TableFrame frame;
    JComboBox typeCom;

    public static void main(String[] args) {
        new AddFrame(new TableFrame());
    }
    public AddFrame(TableFrame frame){
        this.setSize(300, 460);
        this.setLocation(400, 300);
        this.setTitle("增加数据");
        this.setLayout(null);
        this.setDefaultCloseOperation(1);
        this.init();
        this.setVisible(true);
        this.frame = frame;
    }

    private void init(){
        idla = new JLabel("机场编号");
        idla.setSize(60, 30);
        idla.setLocation(30,50);
        idTxt = new JTextField();
        idTxt.setSize(120, 30);
        idTxt.setLocation(100, 50);
        this.add(idla); this.add(idTxt);

        namela = new JLabel("机场名");
        namela.setSize(60, 30);
        namela.setLocation(30,100);
        nameTxt = new JTextField();
        nameTxt.setSize(120, 30);
        nameTxt.setLocation(100,100);
        this.add(namela); this.add(nameTxt);

        addressla = new JLabel("机场位置");
        addressla.setSize(60, 30);
        addressla.setLocation(30,150);
        addressTxt = new JTextField();
        addressTxt.setSize(120, 30);
        addressTxt.setLocation(100,150);
        this.add(addressla); this.add(addressTxt);

        typela =new JLabel("类型");
        typela.setSize(60, 30);
        typela.setLocation(30,200);
        this.add(typela);
        typeCom =new JComboBox();
        typeCom.setSize(120, 30);
        typeCom.setLocation(100,200);
        typeCom.addItem("国际机场");
        typeCom.addItem("国内机场");
        typeCom.addItem("区域机场");
        typeCom.setSelectedItem("军民合用");
        this.add(typeCom);

        phonela = new JLabel("机场电话");
        phonela.setSize(60, 30);
        phonela.setLocation(30,250);
        phoneTxt = new JTextField();
        phoneTxt.setSize(120, 30);
        phoneTxt.setLocation(100,250);
        this.add(phonela); this.add(phoneTxt);

        levella = new JLabel("等级");
        levella.setSize(60, 30);
        levella.setLocation(30,300);
        levelTxt = new JTextField();
        levelTxt.setSize(120, 30);
        levelTxt.setLocation(100,300);
        this.add(levella); this.add(levelTxt);

        JButton but = new JButton("增加");
        but.setSize(60, 30);
        but.setLocation(120,350);
        but.addActionListener(this);
        this.add(but);
    }
    private boolean checkIdExists(int id) {
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
                PreparedStatement pst = c.prepareStatement("SELECT COUNT(*) FROM airports WHERE id = ?");
                pst.setInt(1, id);
                ResultSet resultSet = pst.executeQuery();
                resultSet.next();
                int count = resultSet.getInt(1);
                if (count > 0) {
                    System.out.println("ID 已存在!");
                    return true; // 如果存在相同的 ID，返回true
                } else {
                    System.out.println("ID 不存在!");
                    return false;
                }
            } else {
                System.out.println("数据库连接失败!");
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        return true;
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        String idStr = idTxt.getText().trim();
        if(idStr.length() == 0) {
            JOptionPane.showMessageDialog(null, "机场编号为空");
            idTxt.grabFocus();
            return ;
        }
        int id = Integer.parseInt(idStr);
        if(checkIdExists(id)) {
            JOptionPane.showMessageDialog(null, "机场编号已存在");
            idTxt.grabFocus();
            return ;
        }
        String name = nameTxt.getText().trim();
        if(name.length() == 0) {
            JOptionPane.showMessageDialog(null, "机场名字为空");
            nameTxt.grabFocus();
            return ;
        }
        String address = addressTxt.getText().trim();
        if(address.length() == 0) {
            JOptionPane.showMessageDialog(null, "机场地址为空");
            addressTxt.grabFocus();
            return ;
        }
        String type = typeCom.getSelectedItem().toString();
        if(type.length() == 0) {
            JOptionPane.showMessageDialog(null, "机场类型为空");
            typeTxt.grabFocus();
            return ;
        }
        String phone = phoneTxt.getText().trim();
        if(phone.length() == 0) {
            JOptionPane.showMessageDialog(null, "机场联系方式为空");
            phoneTxt.grabFocus();
            return ;
        }
//        if(phone.length() != 11) {
//            JOptionPane.showMessageDialog(null, "机场联系电话非法");
//            phoneTxt.grabFocus();
//            return ;
//        }
        String level = levelTxt.getText().trim();
        if(level.length() == 0) {
            JOptionPane.showMessageDialog(null, "机场等级为空");
            levelTxt.grabFocus();
            return ;
        }

        AirportDeal deal = new AirportDeal();
        Airport airport = new Airport(id, name, address, type, phone, level);
        deal.addAirport(airport);
        frame.initTable(deal.findAllAirports());
        this.dispose();
    }
}
