
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.reflect.Type;
import java.sql.*;
import java.util.ArrayList;


public class AirportDeal {
    private Connection con;
    private PreparedStatement pst;
    private Statement sta;
    public AirportDeal() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String user = "root"; // 超级管理员用户,拥有对于所有数据对象的所有操作权限
            String passwd = "mysql";
            String url = "jdbc:mysql://82.157.19.240:3306/airport_db?useSSL=false";
            // 用驱动管理类的方法来创建数据库连接对象
            con = DriverManager.getConnection(url, user, passwd);
            System.out.println("数据库连接成功!");
        } catch (ClassNotFoundException ex) {
            // 捕捉并处理类未找到异常
            System.out.println("数据库连接失败！");

        } catch (SQLException ex) {
            // 捕捉并处理SQL异常(创建数据库连接对象的时候或者执行SQL语句的时候)
            System.out.println(ex.toString());
            System.out.println("数据库连接失败！");

        }
    }

    public Airport findAirportById(int id) {
        Airport airport = null;
        try {
            sta = con.createStatement();
            ResultSet res = sta.executeQuery("SELECT * FROM airports WHERE Id = '" + id + "'");
            if(res.next()) {
                airport = new Airport(res.getInt(1), res.getString(2), res.getString(3), res.getString(4), res.getString(5), res.getString(6));
            }
        } catch (SQLException ex) {

        }
        return airport;
    }
    public ArrayList<Airport> findAirportsByName(String name) {
        ArrayList<Airport> result = new ArrayList<>();
        try {
            sta = con.createStatement();
            System.out.println(name);
            ResultSet res = sta.executeQuery("SELECT * FROM airports WHERE Name LIKE '%" + name + "%'");
            while(res.next()) {
                Airport airport = new Airport(res.getInt(1), res.getString(2), res.getString(3), res.getString(4), res.getString(5), res.getString(6));
                result.add(airport);
            }
        } catch (SQLException ex) {

        }
        return result;
    }
    public ArrayList<Airport> findAirportByType(String name, String address, String type) {
        ArrayList<Airport> result = new ArrayList<>();
        try {
            sta = con.createStatement();
            ResultSet res = null;
            if(name.length() == 0 && address.length() == 0) {
                res = sta.executeQuery("SELECT * FROM airports WHERE Type LIKE '%" + type + "%'");
            } else if(name.length() != 0 && address.length() == 0) {
                res = sta.executeQuery("SELECT * FROM airports WHERE Type LIKE '%" + type + "%' AND Name LIKE '%" + name + "%'");
            } else if(name.length() == 0 && address.length() != 0) {
                res = sta.executeQuery("SELECT * FROM airports WHERE Type LIKE '%" + type + "%' AND Address LIKE '%" + address + "%'");
            } else {
                res = sta.executeQuery("SELECT * FROM airports WHERE Type LIKE '%" + type + "%' AND Name LIKE '%" + name + "%' AND Address LIKE '%" + address + "%'");
            }
            while(res.next()) {
                Airport airport = new Airport(res.getInt(1), res.getString(2), res.getString(3), res.getString(4), res.getString(5), res.getString(6));
                result.add(airport);
            }
        } catch (SQLException ex) {

        }
        return result;
    }
    public ArrayList<Airport> findAirportsByAddress(String name, String address) {
        ArrayList<Airport> result = new ArrayList<>();
        try {
            sta = con.createStatement();
            ResultSet res = null;
            if(name.length() == 0) {
                res = sta.executeQuery("SELECT * FROM airports WHERE Address LIKE '%" + address + "%'");
            } else {
                res = sta.executeQuery("SELECT * FROM airports WHERE Address LIKE '%" + address + " %' AND Name LIKE '%" + name + "%'");
            }
            while(res.next()) {
                Airport airport = new Airport(res.getInt(1), res.getString(2), res.getString(3), res.getString(4), res.getString(5), res.getString(6));
                result.add(airport);
            }
        } catch (SQLException ex) {

        }
        return result;
    }
    public void addAirport(Airport airport) {
        try {
            pst = con.prepareStatement("INSERT INTO airports(Id, Name, Address, Type, Phone, Level) VALUES(?, ?, ?, ?, ?, ?)");
            pst.setInt(1, airport.getId());
            pst.setString(2, airport.getName());
            pst.setString(3, airport.getAddress());
            pst.setString(4, airport.getType());
            pst.setString(5, airport.getPhone());
            pst.setString(6, airport.getLevel());
            pst.execute();
        } catch (SQLException ex) {

        }
    }
    public void delAirportById(int id) {
        try {
            pst = con.prepareStatement("DELETE FROM airports WHERE id = ?");
            pst.setInt(1, id);
            pst.execute();
        } catch (SQLException ex) {

        }
    }
    public void updateAirport(Airport airport) {
        try {
            pst = con.prepareStatement("UPDATE airports SET Name = ?, Address = ?, Type = ?, Phone = ?, Level = ? WHERE Id = ?");
            pst.setString(1, airport.getName());
            pst.setString(2, airport.getAddress());
            pst.setString(3, airport.getType());
            pst.setString(4, airport.getPhone());
            pst.setString(5, airport.getLevel());
            pst.setInt(6, airport.getId());
            pst.execute();
        } catch (SQLException ex) {

        }
    }
    public ArrayList<Airport> findAllAirports() {
        ArrayList<Airport> result = new ArrayList<>();
        try {
            sta = con.createStatement();
            ResultSet res = sta.executeQuery("SELECT * FROM airports");
            while(res.next()) {
                Airport airport = new Airport(res.getInt(1), res.getString(2), res.getString(3), res.getString(4), res.getString(5), res.getString(6));
                result.add(airport);
            }
        } catch (SQLException ex) {

        }
        return result;
    }


    // test
    // 添加


    public static void main(String[] args) {
        AirportDeal a = new AirportDeal();
        Airport test1 = new Airport(2, "北京国际机场", "北京市顺义区", "国际机场", "861087654321", "国际一流");
        Airport test2 = new Airport(5, "上海虹桥国际机场", "上海市闵行区", "国际机场", "862138888888", "国际重要");
        Airport test3 = new Airport(15, "西安咸阳国际机场", "西安市渭城区", "国内机场", "862995678901", "国内重要");
        // 添加
        //        a.addAirport(test2);
        // 删除
//        a.delAirportById(1);
        // 修改
//        a.addAirport(test1);
//        a.updateAirport(test1);

    }
}
