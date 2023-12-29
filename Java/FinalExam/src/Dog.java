public class Dog extends Pet{

    public Dog(String name, int age, String color, double weight, String breed) {
        super(name, age, color, weight);
        this.breed = breed;
        this.type = 1;
    }

    @Override
    public void speak() {
         System.out.println("Woof~ " + "I'm " + name + " , a " + age + "-year-old " + breed + " dog");
    }


    @Override
    public String toString() {
        return "Type： dog  " + "Name：" +  name + "  Age：" + age + "  Color：" + color + "  Weight：" + weight + "  Breed：" + breed;
    }
    @Override
    public String toWriteInfo() {
        // Formatting strings
        return String.format("%-30d | %-15s | %-10d | %-10s | %-10.2f | %-10s", 1, name, age, color, weight, breed);
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj) {
            return true;
        }
        if( !(obj instanceof Dog)) {
            return false;
//            System.out.println("Type Error");
        }
        if(super.equals(obj) && breed.equals( ((Dog)obj).breed)) {
            return true;
        }
        return false;
    }

}
