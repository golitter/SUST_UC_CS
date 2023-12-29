import sun.swing.table.DefaultTableCellHeaderRenderer;

import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.JTableHeader;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.JDBCType;
import java.util.ArrayList;

public class TableFrame extends Frame implements ActionListener {
    JTable table;
    JScrollPane panel;
    JLabel namela, addressla, typela;
    JTextField nameTxt, addressTxt;
    JButton nameBt, addressBt, typeBt, delBt, updateBt, addBt, rehBt;
    JComboBox typeCom;
    public TableFrame() {
        this.setSize(820, 600);
        this.setLocation(400, 300);
        this.setTitle("机场信息管理");
        this.setLayout(null);
        this.setVisible(true);
        initControl();
        AirportDeal deal = new AirportDeal();
        initTable(deal.findAllAirports());
//        initTable();
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
    public void initControl() {
        namela = new JLabel("机场名");
        namela.setSize(60, 30);
        namela.setLocation(30, 50);
        this.add(namela);
        nameTxt = new JTextField();
        nameTxt.setText("");
        nameTxt.setSize(120, 30);
        nameTxt.setLocation(100, 50);
        this.add(nameTxt);

        nameBt = new JButton("机场名查询");
        nameBt.setSize(120, 30);
        nameBt.setLocation(250, 50);
        nameBt.addActionListener(this);
        this.add(nameBt);


        typela = new JLabel("类别");
        typela.setSize(60, 30);
        typela.setLocation(420, 50);
        this.add(typela);

        typeCom = new JComboBox();
        typeCom.setSize(80, 30);
        typeCom.setLocation(480, 50);
        typeCom.addItem("国际机场");
        typeCom.addItem("国内机场");
        typeCom.addItem("区域机场");
        this.add(typeCom);

        typeBt = new JButton("类别查询");
        typeBt.setSize(120, 30);
        typeBt.setLocation(580, 50);
        typeBt.addActionListener(this);
        this.add(typeBt);


        addressla = new JLabel("位置");
        addressla.setSize(60, 30);
        addressla.setLocation(30, 100);
        this.add(addressla);

        addressTxt = new JTextField();
        addressTxt.setText("");
        addressTxt.setSize(120, 30);
        addressTxt.setLocation(100, 100);
        this.add(addressTxt);

        addressBt = new JButton("位置查询");
        addressBt.setSize(120, 30);
        addressBt.setLocation(250, 100);
        addressBt.addActionListener(this);
        this.add(addressBt);


        delBt = new JButton("删除");
        delBt.setSize(60, 30);
        delBt.setLocation(420, 100);
        delBt.addActionListener(this);
        this.add(delBt);

        updateBt = new JButton("修改");
        updateBt.setSize(60, 30);
        updateBt.setLocation(500, 100);
        updateBt.addActionListener(this);
        this.add(updateBt);

        addBt = new JButton("添加");
        addBt.setSize(60, 30);
        addBt.setLocation(580, 100);
        addBt.addActionListener(this);
        this.add(addBt);

        rehBt = new JButton("刷新");
        rehBt.setSize(60, 30);
        rehBt.setLocation(660, 100);
        rehBt.addActionListener(this);
        this.add(rehBt);
    }
    public void initTable(ArrayList list) {
        if(panel != null) {
            this.remove(panel);
        }
        String[] titles = {"编号",
            "机场名", "机场位置", "类型", "电话", "等级"
        };
        String[][] values = new String[list.size()][6];
        for(int i = 0; i < list.size(); ++i) {
            Airport airport = (Airport) list.get(i);
            values[i][0] = "    " + String.valueOf(airport.getId());
            values[i][1] = airport.getName();
            values[i][2] = airport.getAddress();
            values[i][3] = airport.getType();
            values[i][4] = airport.getPhone();
            values[i][5] = airport.getLevel();
        }
        table = new JTable(values, titles);
        panel = new JScrollPane(table);
        panel.setSize(800, 500);
        panel.setLocation(0, 150);

        table.setFont(new Font("楷体", Font.PLAIN, 18));
        table.setRowHeight(50);
        JTableHeader header = table.getTableHeader();
        header.setFont(new Font("楷体", Font.BOLD, 26)); // 设置表头字体大小
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment(JLabel.CENTER); // 将单元格文本内容居中对齐
// 对每一列应用居中对齐的渲染器
        for (int i = 1; i < table.getColumnCount(); i++) {
            table.getColumnModel().getColumn(i).setCellRenderer(centerRenderer);
        }

        this.add(panel);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        JButton bt = (JButton) e.getSource();
        AirportDeal airportDeal = new AirportDeal();
        if(bt.getText().equals("机场名查询")) {
            if(nameTxt.getText().trim().equals("")) {
                this.initTable(airportDeal.findAllAirports());
            } else {
                this.initTable(airportDeal.findAirportsByName(nameTxt.getText().trim()));
            }
        } else if(bt.getText().equals("位置查询")) {
            if(addressTxt.getText().trim().equals("")) {
                this.initTable(airportDeal.findAllAirports());
            } else {
                String name = nameTxt.getText();
                this.initTable(airportDeal.findAirportsByAddress(name, addressTxt.getText().trim()));
            }
        } else if(bt.getText().equals("类别查询")) {
            String name = nameTxt.getText();
            String address = addressTxt.getText();
            this.initTable(airportDeal.findAirportByType(name, address, typeCom.getSelectedItem().toString()));
        } else if (bt.getText().equals("删除")) {
            int row = table.getSelectedRow();
            if(row == -1) {

            } else {
                airportDeal.delAirportById(Integer.parseInt(table.getValueAt(row, 0).toString().trim()));
                this.initTable(airportDeal.findAllAirports());
            }
        } else if(bt.getText().equals("修改")) {
            int row = table.getSelectedRow();
            if(row == -1) {

            } else {
                int num = Integer.parseInt(table.getValueAt(row,0).toString().trim());
                System.out.println(num);
                UpdateFrame updateFrame = new UpdateFrame(num, this);
            }
        } else if(bt.getText().equals("添加")) {
            AddFrame addFrame = new AddFrame(this);
            System.out.println("dkfj;");
        } else if(bt.getText().equals("刷新")) {
            this.initTable(airportDeal.findAllAirports());
        }
    }

    public static void main(String[] args) {
        new TableFrame();
    }
}