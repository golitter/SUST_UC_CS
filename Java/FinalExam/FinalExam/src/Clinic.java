import java.io.*;
import java.util.ArrayList;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

public class Clinic {
    private ArrayList<Pet> pets;
    private String name = "YH";

    public Clinic() {
        pets = new ArrayList<>();
        // Importing Clinic Information and Pet Information
        readFromClinicsDetails();
        readFromPetDetails();
    }

    public String getName() {
        return name;
    }

    /**
     * Write the program's data about the clinic into the file ClinicsDetails.txt
     */
    private void writeToClinicsDetails() {
        // Processing of current clinic information
        // deposit a document
        try (FileWriter writeFile = new FileWriter("ClinicsDetails.txt")) {
            // Writing intuitive content to a file
            writeFile.write("Clinic Information: \n");
            writeFile.write("Clinic Name: " + name + '\n');
            writeFile.write("Number of cats: " + findCountOfCat() + '\n');
            writeFile.write("Number of dogs: " + findCountOfDog() + '\n');
            writeFile.write("Colors that make up the largest percentage of pets: " + findMoreColor() + '\n');
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Importing information from the file ClinicsDetails.txt
     */
    private void readFromClinicsDetails() {
        try (BufferedReader br = new BufferedReader(new FileReader("ClinicsDetails.txt"))) {
            String line = br.readLine(); // Read the first line, "Clinic Information."
            line = br.readLine(); // Read the clinic name line.
            // If it is empty, set the name
            if(line == null) {
                name = "YH";
                return ;
            }
            String[] strArr = line.split(":");
            name = strArr[1].trim();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Write the program pet's data into the PetDetails.txt file
     */
    private void writePetDetails() {
        try(FileWriter writeFile = new FileWriter("PetDetails.txt")) {
            writeFile.write("Pet Information\n");
            // Formatting strings and printing them
            writeFile.write(String.format("%-30s  %-16s  %-11s  %-11s  %-11s  %-11s\n", "Pet type (1 dog, 2 cats)", "Name", "Age", "Color", "Weight", "Breed") );
            for(Pet pet: pets) {
                writeFile.write(pet.toWriteInfo() + "\n");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Importing information from within the PetDetails.txt file
     */
    private void readFromPetDetails() {
        try (BufferedReader br = new BufferedReader(new FileReader("PetDetails.txt"))) {
            String line;
            // Read the first line, the pet message line, which is irrelevant for program reads
            line = br.readLine();
            // Read the second line, which is the content of the intuitive description of the data written, independent of the program read-in
            line = br.readLine();
            while( (line = br.readLine()) != null) {
                // Reading method
//                "getType() " + getName() + " " + getAge() + " " + getColor() + " " + getWeight() + " " + getBreed();

                // Cutting according to `|`
                // Remove spaces and perform a type conversion to get the corresponding type of information
                String[] strArr = line.split("\\|");
                int petType = Integer.parseInt(strArr[0].trim());
                String petName = strArr[1].trim();
                int petAge = Integer.parseInt(strArr[2].trim());
                String petColor = strArr[3].trim();
                double petWeight = Double.parseDouble(strArr[4].trim());
                String petBreed = strArr[5].trim();

                // Instantiate objects based on different pet types and add them to the clinic
                if(petType == 1) {
                    Dog dog = new Dog(petName, petAge, petColor, petWeight, petBreed);
                    addPet(dog);
                } else {
                    Cat cat = new Cat(petName, petAge, petColor, petWeight, petBreed);
                    addPet(cat);
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * When the program is about to exit, the information is stored in a file.
     */
    public void fromExeAppForWrite() {
        writePetDetails();
        writeToClinicsDetails();
    }


    /**
     * Get the number of cats
     * @return count of cats
     */
    private int findCountOfCat() {
        int countOfCat = 0;
        for(Pet pet: pets) {
            if(pet.getType() == 2) ++countOfCat;
        }
        return countOfCat;
    }

    /**
     * Get the number of dogs
     * @return count of dogs
     */
    private int findCountOfDog() {
        int countOfDog = 0;
        for(Pet pet: pets) {
            if(pet.getType() == 1) ++countOfDog;
        }
        return countOfDog;
    }

    /**
     * Get the color that has the most pets in it
     * @return broadest color
     */
    private String findMoreColor() {
        // Mapping colors and quantities with Map
        Map<String, Integer> mapColorToCounts = new TreeMap<>();
        // Define the initial value of the color
        String moreColor = "None";

        // Iterate over pets and remap the number of current pet colors
        for(Pet pet: pets) {
            int nowColorCount = mapColorToCounts.getOrDefault(pet.getColor(), 0);
            mapColorToCounts.put(pet.getColor(), ++nowColorCount);
        }

        // Define the number of pets corresponding to the color
        int maxCount = -1;
        // Record the number of times the maximum value occurs
        int cnt = 0;
        // After converting to a Set, it is traversed with an iterator to update the color with the maximum number of pets and the corresponding number of pets
        Set<Map.Entry<String,Integer>> entrySet = mapColorToCounts.entrySet();
        for(Map.Entry<String, Integer> iterator: entrySet) {
            if(iterator.getValue() > maxCount) {
                maxCount = iterator.getValue();
                cnt = 1;
            } else if(iterator.getValue() == maxCount) ++cnt;
        }
        // If the maximum value is -1, it means there is no pet, just return it directly
        if(maxCount == -1) return moreColor;

        // Record the most occurring color
            // Depending on the number of maxima, the spacers are set to reach the final output as [ color1, color2, ... color_n]
        moreColor = " [ ";
        for(Map.Entry<String,Integer> iterator: entrySet) {
            if(iterator.getValue() == maxCount) {
                moreColor += iterator.getKey();
                --cnt;
                if(cnt > 0) {
                    moreColor += " , ";
                } else moreColor += " ]";
            }
        }
        return moreColor;
    }

    /**
     * Displaying clinic information
     */
    public void displayClinicsDetails() {
        System.out.println("The name of this clinic： " + name);
        System.out.println("Number of cat pet registrations： " + findCountOfCat());
        System.out.println("Number of dog pet registrations： " + findCountOfDog());
        System.out.println("The main colors in pets are： " + findMoreColor());
    }

    /**
     * Specific Pets
     * @param other Pets to Judge
     * @return Returns true if present, otherwise returns
     */
    public boolean notEmpty(Pet other) {
        for(Pet pet: pets) {
            if(pet.equals(other)) return true;
        }
        return false;
    }

    /**
     * Add Pet
     * @param pet Pets to add
     */
    public void addPet(Pet pet) {
        pets.add(pet);
    }

    /**
     * Delete Pets
     * @param pet Pets to be deleted
     * @return Returns whether the deletion was successful, true - success, false - failure
     */
    public boolean removePet(Pet pet) {
        return pets.remove(pet);
    }

    /**
     * Display by pet color
     */
    public void displayPetByColor() {
        // Mapping a color to a list of pets of that color with Map
        Map<String, ArrayList<Pet>> mapPetToColor = new TreeMap<>();
        for(Pet pet: pets) {
            // If the list of pets of the current color is empty, allocate space.
            ArrayList<Pet> temp = mapPetToColor.getOrDefault(pet.getColor(), null);
            if(temp == null) {
                temp = new ArrayList<>();
            }
            // Add this pet to the pet list
            temp.add(pet);
            // Updates to the list of pets of that color
            mapPetToColor.put(pet.getColor(), temp);
        }
        // Print out the color and the corresponding color of the pet
        mapPetToColor.forEach( (key, value) -> {
            System.out.println("Color：" + key);
            for(Pet pet: value) {
                System.out.println(pet);
            }
        });
    }

    /**
     * Display by pet type
     * 同理
     */
    public void displayPetByBreed() {
        // Mapping pet types and corresponding pet lists with Map
        Map<Integer, ArrayList<Pet>> mapPetToColor = new TreeMap<>();

        // Remapping the pet list for pet types
        for(Pet pet: pets) {
            ArrayList<Pet> temp = mapPetToColor.getOrDefault(pet.getType(), null);
            // If null, create a pet list instance
            if(temp == null) {
                temp = new ArrayList<>();
            }
            // Adding pets to the pet list
            temp.add(pet);
            // carry out remapping
            mapPetToColor.put(pet.getType(), temp);
        }
        // Output with foreach statements
        mapPetToColor.forEach( (key, value) -> {
            // Determine if you are currently a dog or cat based on the key value.
            System.out.println("Pet Category：" + (key == 1 ? "Dog" : "Cat"));
            for(Pet pet: value) {
                System.out.println(pet);
            }
        });
    }

    /**
     * Default Display
     */
    public void displayDefaultAllPets() {
        for(Pet pet: pets) {
            System.out.println(pet);
        }
    }

    /**
     * Search by name
     * @param name Name to search for
     */
    public void searchPetByName(String name) {
        // Define a boolean value that determines if the pet has already been found
        boolean ok = false;
        for(Pet pet: pets) {
            // If there is no match, continue
            if( !name.equalsIgnoreCase(pet.getName())) continue;
            // Otherwise, set the boolean ok to true and output speak
            ok = true;
            pet.speak();
        }
        // If the boolean ok is true, it means that the pet in question was found, making an early return
        if(ok) return ;
        System.out.println("None to be found.");
    }

    /**
     * Search by color
     * @param color Colors to search for
     */
    public void searchPetByColor(String color) {
        // Define a boolean value that determines if the pet has already been found
        boolean ok = false;
        for(Pet pet: pets) {
            // If there is no match, continue
            if( !color.equalsIgnoreCase(pet.getColor())) continue;
            // Otherwise, set the boolean ok to true and output pet of information
            ok = true;
            System.out.println(pet);
        }
        // If the boolean ok is true, it means that the pet in question was found, making an early return
        if(ok) return ;
        System.out.println("None to be found.");
    }
}
