import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ClinicTest {

    @Test
    public void testInputDogInformation() {
        Clinic myclinic = new Clinic();
        // Max | 4 years | Brown | 50 | Labrador Retriever
        Pet dog = new Dog("Max", 4,"Brown", 50, "Labrador Retriever");
        myclinic.addPet(dog);

        // The delete function returns true if the deletion is successful, otherwise it returns false.
        // Since the dog is inserted, it is possible to delete it for the first time, i.e., it returns true
        assertEquals(true,myclinic.removePet(dog), "The Test didn't Pass." );

        // After deleting, deleting again will report an error
        assertEquals(false,myclinic.removePet(dog), "The Test didn't Pass." );

    }

    @Test
    public void testInputCatInformation() {
        Clinic myclinic = new Clinic();
        // Whiskers | 3 years | Gray | 8B | ritish Shorthair
        Pet cat = new Cat("Whiskers", 3, "Gray", 88, "ritish Shorthair");
        myclinic.addPet(cat);

        // The delete function returns true if the deletion is successful, otherwise it returns false.
            // Since the dog is inserted, it is possible to delete it for the first time, i.e., it returns true
        assertEquals(true, myclinic.removePet(cat), "The Test didn't Pass.");

        // After deleting, deleting again will report an error
        assertEquals(false, myclinic.removePet(cat), "The Test didn't Pass.");
    }
}