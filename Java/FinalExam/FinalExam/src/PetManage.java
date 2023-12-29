import com.sun.xml.internal.bind.v2.TODO;

import java.io.IOException;
import java.util.Scanner;

public class PetManage {
    private Clinic clinic;
    private Scanner sc = new Scanner(System.in);

    // Test
    public static void main(String[] args) throws IOException {
        PetManage pm = new PetManage();
        pm.MainMenu();
    }

    public PetManage() {
        clinic = new Clinic();
    }

    /**
     * The main interface of the pet management system
     */
    public void MainMenu() throws  IOException {
        clinic.displayClinicsDetails();
        int choice = -1;
        do {
            System.out.println("Welcome to " + clinic.getName() + " Veterinary Clinic");
            System.out.println("1, Add Pet");
            System.out.println("2, Remove Pet");
            System.out.println("3, Showcase");
            System.out.println("4, Search");
            System.out.println("5, Displaying clinic information");
            System.out.println("6, Exit");
            System.out.println("Please enter the option you want to select: ");

            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    addPetToClinic();
                    break;
                case 2:
                    removePetFromClinic();
                    break;
                case 3:
                    displayMenu();
                    break;
                case 4:
                    searchPetMenu();
                    break;
                case 5:
                    displayClinicsDetails();
                case 6:
                    clinic.fromExeAppForWrite();
                    break;
                default:
                    System.out.println("Illegal option, please re-enter");
                    break;
            }
        } while(choice != 6);
    }

    /**
     * Get a valid age value
     * @return age of value
     */
    private int getValidAge() {
        System.out.println("Please enter its age: ");
        int age = sc.nextInt();
        sc.nextLine();
        while(age < 0 || age > 100) {
            System.out.println("Please enter a valid age value: ");
            age = sc.nextInt();
            sc.nextLine();
        }
        return age;
    }

    /**
     * Get a valid weight value
     * @return weight of valid
     */
    private double getValidWeight() {
        System.out.println("Please enter its weight: ");
        double weight = sc.nextDouble();
        sc.nextLine();
        while(weight < 0) {
            System.out.println("Please enter a valid weight value: ");
            weight = sc.nextDouble();
            sc.nextLine();
        }
        return weight;
    }
    /**
     *  Get information about the specific pet to be operated on
     * @param operationName Name of the operation
     * @return Specific pets
     */
    private Pet getPet(String operationName) {
        Pet pet = new Pet();
        // Define a Boolean variable to determine if the input is legitimate: the task requires that there can be no null values
        boolean notHasEmptyValue = true;

        // Read in the pet's details in turn
        System.out.println("We're going to " + operationName + " pet now.");
        System.out.println("Please enter its name: ");
        String name = sc.nextLine();
        // If the read-in is null, notHasEmptyValue set false
        if(name.length() == 0) notHasEmptyValue = false;

        // Get age value
        int age = getValidAge();

        System.out.println("Please enter its color");
        String color = sc.nextLine();
        // If the read-in is null, notHasEmptyValue set false
        if(color.length() == 0) notHasEmptyValue = false;

        // Get weight of pet
        double weight = getValidWeight();

        // Get pet of type
        System.out.println("There are several types of pets: ");
        System.out.println("1, Dog");
        System.out.println("2, Cat");
        System.out.println("Please enter its type");
        int petType = sc.nextInt();
        sc.nextLine();

        // Get pet of type
        System.out.println("Please enter a species：");
        String breed = sc.nextLine();
        // If the read-in is null, notHasEmptyValue set false
        if(breed.length() == 0) notHasEmptyValue = false;
        // If the boolean value is false, it means there is a null value and the pet read in is not legal
        if(!notHasEmptyValue) {
            System.out.println("Null value, end!");
            return null;
        }

        // Instance creation based on reading in pet types
        if(petType == 1) {
            Dog dog = new Dog(name, age, color, weight, breed);
            pet = dog;
        } else if(petType == 2) {
            Cat cat = new Cat(name, age, color, weight, breed);
            pet = cat;
        } else {
            System.out.println("Error");
        }
        return pet;
    }

    /**
     * Adding pet
     */
    private void addPetToClinic() {
        // Get information about the pet you want to add
        Pet pet = getPet("add");
        // If the value is null, it means, there is a null value or an error in the read.
        if(pet == null) {
            System.out.println("Please enter valid pet information");
            return ;
        }
        // If it already exists
        if(clinic.notEmpty(pet)) {
            System.out.println("It's been there before.");
            return ;
        }
        clinic.addPet(pet);
        System.out.println("Pet added successfully");
    }
    /**
     * Removing pet
     */
    private void removePetFromClinic() {
        // Get information about the pet to be deleted
        Pet pet = getPet("remove");
        // If the value is null, it means, there is a null value or an error in the read.
        if(pet == null) {
            System.out.println("Deletion failed, please check input of pet information, etc.");
            return ;
        }
        // Delete successfully, return to this statement
        if(clinic.removePet(pet)) {
            System.out.println("Deleted successfully");
            return ;
        }
        System.out.println("The pet was not found in the in-clinic pets");

    }

    /**
     * Displaying pet interface information
     */
    private void displayMenu() {
        int choice = -1;
        do {
            System.out.println("Make a selection to display by that type");
            System.out.println("1, Show by color");
            System.out.println("2, Show by type");
            System.out.println("3, Default Display");
            System.out.println("4, Exit");
            System.out.println("Please export the option you want to select: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    displayStatisticsByColor();
                    break;
                case 2:
                    displayStatisticsByBreed();
                    break;
                case 3:
                    displayDefaultAllPets();
                    break;
                case 4:
                    break;
                default:
                    System.out.println("Please enter a valid option number");
                    break;
            }
        } while(choice != 4);
    }

    /**
     * Show by Pet Color
     */
    private void displayStatisticsByColor() {
        clinic.displayPetByColor();
    }

    /**
     * Show by Pet Type
     */
    private void displayStatisticsByBreed() {
        clinic.displayPetByBreed();
    }

    /**
     * Show by default
     */
    private void displayDefaultAllPets() {
        clinic.displayDefaultAllPets();
    }

    /**
     * Search for a specific pet
     */
    private void searchPetMenu() {
        int choice = -1;
        do {
            System.out.println("Options available: ");
            System.out.println("1, Search by name");
            System.out.println("2, Search by color");
            System.out.println("3, Exit");
            System.out.println("Please enter the options to be selected: ");
            choice = sc.nextInt();
            sc.nextLine();

            if(choice == 3) continue;

            if(choice <= 2 && choice >= 1) {
                String str;
                switch (choice) {
                    case 1:
                        System.out.println("Please output the name of the query: ");
                        str = sc.nextLine();
                        clinic.searchPetByName(str);
                        break;
                    case 2:
                        System.out.println("Please output the color to be queried: ");
                        str = sc.nextLine();
                        clinic.searchPetByColor(str);
                        break;
                }
            } else {
                System.out.println("Error!");
            }
        } while(choice != 3);
    }

    // Displaying clinic information
    private void displayClinicsDetails() {
        clinic.displayClinicsDetails();
    }
}
