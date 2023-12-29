public class Airport {
    private int id;
    private String name, address, type, phone, level;
    public Airport(int id, String name, String address, String type, String phone, String level) {
        this.id = id;
        this.name = name;
        this.address = address;
        this.type = type;
        this.phone = phone;
        this.level = level;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getLevel() {
        return level;
    }

    public void setLevel(String level) {
        this.level = level;
    }
    @Override
    public String toString() {
        return "Airport{ " +
                "id=" + id +
                ", name='" + name + '\'' +
                ", address='" + address + '\'' +
                ", type='" + type + '\'' +
                ", phone='" + phone + '\'' +
                ", level='" + level + '\'' +
                '}'+"\n";
    }
}
