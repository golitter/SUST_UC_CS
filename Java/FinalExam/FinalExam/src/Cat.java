public class Cat extends Pet{
    public Cat(String name, int age, String color, double weight, String breed) {
        super(name, age, color, weight);
        this.breed = breed;
        this.type = 2;
    }

    @Override
    public void speak() {
        System.out.println("Miaow~ " + "I'm " + name + " , a " + age + "-year-old " + breed + " cat");
    }


    @Override
    public String toString() {
        return "Type： Cat  " + "Name：" +  name + "  Age：" + age + "  Color：" + color + "  Weight：" + weight + "  Breed：" + breed;
    }

    @Override
    public String toWriteInfo() {
//        return "2 " + getName() + " " + getAge() + " " + getColor() + " " + getWeight() + " " + getBreed();
        return String.format("%-30d | %-15s | %-10d | %-10s | %-10.2f | %-10s", 2, name, age, color, weight, breed);
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj) {
            return true;
        }
        if( !(obj instanceof Pet)) {
            return false;
//            System.out.println("Type Error");
        }
        if(super.equals(obj) && breed.equals(((Cat)obj).breed)) {
            return true;
        }
        return false;
    }

}
