import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UpdateFrame extends JFrame implements ActionListener {
    JLabel idla, namela,addressla,typela, phonela, levella;
//
    JTextField idTxt, nameTxt, addressTxt, typeTxt, phoneTxt, levelTxt;
    JComboBox typeCom;

    JButton bt;
    TableFrame frame;
    public UpdateFrame(int row, TableFrame frame)
    {
        this.setSize(300, 460);
        this.setLocation(400, 300);
        this.setTitle("修改数据");
        this.setLayout(null);
//        this.setDefaultCloseOperation(1);
        this.init(row);
        this.setVisible(true);
        this.frame = frame;
    }

    private void init(int row)
    {
        AirportDeal deal = new AirportDeal();
        Airport airport = deal.findAirportById(row);
        idla = new JLabel("编号");
        idla.setSize(60, 30);
        idla.setLocation(30,50);
        this.add(idla);
        idTxt = new JTextField();
        idTxt.setSize(120, 30);
        idTxt.setLocation(100,50);
        idTxt.setEnabled(false);
        idTxt.setText(String.valueOf(airport.getId()));
        this.add(idTxt);

        namela = new JLabel("名字");
        namela.setSize(60, 30);
        namela.setLocation(30,100);
        this.add(namela);
        nameTxt = new JTextField();
        nameTxt.setSize(120, 30);
        nameTxt.setLocation(100,100);
        nameTxt.setText(airport.getName());
        this.add(nameTxt);

        addressla = new JLabel("位置");
        addressla.setSize(60, 30);
        addressla.setLocation(30,150);
        this.add(addressla);
        addressTxt = new JTextField();
        addressTxt.setSize(120, 30);
        addressTxt.setLocation(100,150);
        addressTxt.setText(String.valueOf(airport.getAddress()));
        this.add(addressTxt);

        typela = new JLabel("类型");
        typela.setSize(60, 30);
        typela.setLocation(30,200);
        this.add(typela);
        typeCom =new JComboBox();
        typeCom.setSize(120, 30);
        typeCom.setLocation(100,200);
        typeCom.addItem("军民合用");
        typeCom.addItem("军用机场");
        typeCom.addItem("民用机场");
        this.add(typeCom);

        phonela = new JLabel("电话");
        phonela.setSize(60, 30);
        phonela.setLocation(30,250);
        this.add(phonela);
        phoneTxt = new JTextField();
        phoneTxt.setSize(120, 30);
        phoneTxt.setLocation(100,250);
        phoneTxt.setText(airport.getPhone());
        this.add(phoneTxt);

        levella = new JLabel("等级");
        levella.setSize(60, 30);
        levella.setLocation(30,300);
        this.add(levella);
        levelTxt = new JTextField();
        levelTxt.setSize(120, 30);
        levelTxt.setLocation(100,300);
        levelTxt.setText(airport.getLevel());
        this.add(levelTxt);

        bt = new JButton("修改");
        bt.setSize(60, 30);
        bt.setLocation(120,350);
        bt.addActionListener(this);
        this.add(bt);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        AirportDeal deal = new AirportDeal();
        int id = Integer.parseInt(idTxt.getText().trim());
        String name = nameTxt.getText().trim();
        String address = addressTxt.getText().trim();
        String type = typeCom.getSelectedItem().toString();
        String phone = phoneTxt.getText().trim();
        String level = levelTxt.getText().trim();
//        if(phone.length() != 11) {
//            JOptionPane.showMessageDialog(null, "机场联系电话非法");
//            phoneTxt.grabFocus();
//            return ;
//        }
        Airport airport = new Airport(id, name, address, type, phone, level);
        deal.updateAirport(airport);
        frame.initTable(deal.findAllAirports());
        this.dispose();
    }
}
