public class Pet {
    protected String name;
    protected int age;
    protected String color;
    protected double weight;
    // Define type 1 to be a dog, 2 to be a cat
    protected int type;
    protected String breed;

    public Pet() {
    }
    public Pet(String name, int age, String color, double weight) {
        this.name = name;
        this.age = age;
        this.color = color;
        this.weight = weight;
    }
    public void speak() {
        System.out.println("I am pet");
    }
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }
    public String getBreed() {
        return breed;
    }
    public void setBreed(String breed) {
        this.breed = breed;
    }

    @Override
    public String toString() {
        return getName() + " " + getAge() + " " + getColor() + " " + getWeight();
    }
    public String toWriteInfo() {
        return "";
    }


    @Override
    public boolean equals(Object obj) {
        if(this == obj) {
            return true;
        }
        if( !(obj  instanceof Pet)) {
            System.out.println("Type Error");
            return false;
        }
        Pet p = (Pet)obj;
        if(name.equals(p.getName()) && age == ((Pet) obj).getAge()
            && color.equals(((Pet) obj).getColor())
                && weight == ((Pet) obj).weight
                && type == ((Pet) obj).getType()
        ) {
            return true;
        }
        return false;
    }
}
