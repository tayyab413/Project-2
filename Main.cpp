#include <iostream> // For input and output operations
#include <iomanip>  // For controlling output formatting
#include <cstdlib>  // For random number generation
using namespace std;

// Forward declaration of classes
class Ticket;
class Seat;

// Base class for Users
class User {
protected:
    string name;     // User's name
    string password; // User's password

public:
    User() {
        name = "";     // Initialize name as empty
        password = ""; // Initialize password as empty
    }

    // Login method to check user credentials
    virtual bool login(const string& id, const string& pass) {
        if (name == id && password == pass) { // If credentials match
            cout << "\n\t\t\t\t     Login successful!\n"; // Print success message
            return true; // Return true for successful login
        }
        cout << "\n\t\t\t\t     Login failed!\n"; // Print failure message
        return false; // Return false for failed login
    }

    // Virtual method to display menu, must be overridden in derived classes
    virtual void displayMenu() = 0;

    virtual ~User() {} // Destructor
};

// Admin class that inherits from User
class Admin : public User {
public:
    Admin() {
        name = "admin";      // Admin username is 'admin'
        password = "admin123"; // Admin password is 'admin123'
    }

    // Display menu for admin
    void displayMenu() override {
        system("cls"); // Clear the screen
        cout << "\n\t\t\t\t==============================================\n";
        cout << "\t\t\t\t          ADMIN MENU                         \n";
        cout << "\t\t\t\t==============================================\n";
        cout << "\t\t\t\t|  1. View All Movies                       |\n";  // Option to view all movies
        cout << "\t\t\t\t|  2. Exit                                  |\n";             // Option to exit admin menu
        cout << "\t\t\t\t==============================================\n";
    }

    // Method to display available movies
    void viewMovies(const string movies[], int movieCount) {
        system("cls"); // Clear the screen
        cout << "\n\t\t\t\t====================================================================================\n";
        cout << "\t\t\t\t          		AVAILABLE MOVIES                   \n";
        cout << "\t\t\t\t====================================================================================\n";
        for (int i = 0; i < movieCount; ++i) { // Loop through all movies
            cout << "\t\t\t\t|     " << i + 1 << ". " << movies[i] << " |\n"; // Print movie details
        }
        cout << "\t\t\t\t====================================================================================\n";
    }
};

// Ticket class to manage ticket details
class Ticket {
private:
    string ticketID; // Unique ticket ID
    string movie;    // Movie name
    int seatNumber;  // Seat number

public:
    // Constructor that generates a ticket for a movie and seat
    Ticket(string movieName, int seat) {
        ticketID = generateTicketID(); // Generate ticket ID
        movie = movieName; // Assign movie name
        seatNumber = seat; // Assign seat number
    }

    // Generate a random ticket ID
    string generateTicketID() {
        string id = "TICK"; // Start of ticket ID
        int randomID = rand() % 10000; // Generate a random number
        id += (randomID / 1000) + '0';  // Add first digit of random ID
        id += ((randomID / 100) % 10) + '0'; // Add second digit
        id += ((randomID / 10) % 10) + '0';  // Add third digit
        id += (randomID % 10) + '0';  // Add last digit
        return id; // Return the generated ticket ID
    }

    // Display ticket details
    void displayTicket() {
        system("cls"); // Clear the screen
        cout << "\n\t\t\t\t========================================================================\n";
        cout << "\t\t\t\t        	  TICKET DETAILS                     \n";
        cout << "\t\t\t\t========================================================================\n";
        cout << "\t\t\t\t|     Ticket ID: " << ticketID << "               |\n";  // Print ticket ID
        cout << "\t\t\t\t|     Movie: " << movie << "                    |\n";          // Print movie name
        cout << "\t\t\t\t|     Seat Number: " << seatNumber << "           |\n"; // Print seat number
        cout << "\t\t\t\t========================================================================\n";
    }
};

// Seat class to manage seat availability
class Seat {
private:
    bool seats[50]; // Array to store seat availability (50 seats)

public:
    // Constructor to initialize all seats as unbooked
    Seat() {
        for (int i = 0; i < 50; ++i) {
            seats[i] = false; // All seats are unbooked initially
        }
    }

    // Check if a specific seat is available
    bool isAvailable(int seatNumber) {
        return !seats[seatNumber - 1]; // Return true if seat is unbooked
    }

    // Book a specific seat
    void bookSeat(int seatNumber) {
        seats[seatNumber - 1] = true; // Mark the seat as booked
    }
};

// Customer class that inherits from User
class Customer : public User {
public:
    // Constructor to initialize customer with a username and password
    Customer(const string& username, const string& pass) {
        name = username;  // Set customer name
        password = pass;  // Set customer password
    }

    // Display menu for customer
    void displayMenu() override {
        system("cls"); // Clear the screen
        cout << "\n\t\t\t\t==============================================\n";
        cout << "\t\t\t\t         CUSTOMER MENU                       \n";
        cout << "\t\t\t\t==============================================\n";
        cout << "\t\t\t\t|  1. View Movies                          |\n";  // Option to view all movies
        cout << "\t\t\t\t|  2. Book Ticket                          |\n"; // Option to book a ticket
        cout << "\t\t\t\t|  3. Exit                                 |\n";        // Option to exit customer menu
        cout << "\t\t\t\t==============================================\n";
    }

    // Method to display available movies
    void viewMovies(const string movies[], int movieCount) {
        system("cls"); // Clear the screen
        cout << "\n\t\t\t\t====================================================================================\n";
        cout << "\t\t\t\t          			AVAILABLE MOVIES                   \n";
        cout << "\t\t\t\t====================================================================================\n";
        for (int i = 0; i < movieCount; ++i) { // Loop through all movies
            cout << "\t\t\t\t|     " << i + 1 << ". " << movies[i] << " |\n"; // Print movie details
        }
        cout << "\t\t\t\t====================================================================================\n";
    }

    // Method to book a ticket for a movie and seat
    void bookTicket(const string movies[], int movieCount, Seat& seatManager) {
        int choice, seatNumber; 
        viewMovies(movies, movieCount); // Display available movies
        cout << "\n\t\t\t\t| Enter the movie number to book: ";
        cin >> choice; // Get user's movie choice

        if (choice > 0 && choice <= movieCount) { // If valid movie choice
            cout << "\t\t\t\t| Enter seat number (1-50): ";
            cin >> seatNumber; // Get seat number from user

            if (seatManager.isAvailable(seatNumber)) { // Check if seat is available
                seatManager.bookSeat(seatNumber); // Book the seat
                Ticket ticket(movies[choice - 1], seatNumber); // Create ticket
                ticket.displayTicket(); // Display ticket details
                cout << "\n\t\t\t\t| Booking successful!\n"; // Print booking success message
            } else {
                cout << "\n\t\t\t\t| Seat already booked. Please choose a different seat.\n"; // If seat is taken
            }
        } else {
            cout << "\n\t\t\t\t| Invalid choice!\n"; // If invalid movie choice
        }
    }
};

// Function to prompt the user to press a key to continue
void pressToContinue() {
    cout << "\n\t\t\t\t| Press Enter to continue...";
    cin.ignore(); // Ignore any previous input
    cin.get();    // Wait for the user to press Enter
}

int main() {
    Admin admin; // Create an admin object
    const int maxMovies = 10; // Maximum number of movies
    string movies[maxMovies] = {
        "The Shawshank Redemption | Drama | 142 mins | 14/05/2023 | 19:00 | $12.50",
        "The Dark Knight | Action | 152 mins | 15/05/2023 | 21:00 | $15.00",
        "Inception | Sci-Fi | 148 mins | 16/05/2023 | 20:00 | $14.00",
        "Pulp Fiction | Crime | 154 mins | 17/05/2023 | 22:00 | $13.00",
        "The Godfather | Drama | 175 mins | 18/05/2023 | 18:00 | $16.00",
        "Forrest Gump | Comedy | 142 mins | 19/05/2023 | 20:30 | $11.50",
        "The Matrix | Sci-Fi | 136 mins | 20/05/2023 | 21:00 | $12.00",
        "Avengers: Endgame | Action | 181 mins | 21/05/2023 | 19:30 | $18.00",
        "Titanic | Romance | 195 mins | 22/05/2023 | 18:30 | $14.50",
        "Joker | Thriller | 122 mins | 23/05/2023 | 20:00 | $12.00"
    };
    int movieCount = maxMovies; // Set movie count

    Seat seatManager; // Create seat manager object

    while (true) { // Main loop for the system
        system("cls"); // Clear the screen
        cout << "\n\t\t\t\t==============================================\n";
        cout << "\t\t\t\t        MOVIE TICKETING SYSTEM               \n";
        cout << "\t\t\t\t==============================================\n";
        cout << "\t\t\t\t|  1. Admin Login                           |\n";   // Option for admin login
        cout << "\t\t\t\t|  2. Customer Login                        |\n"; // Option for customer login
        cout << "\t\t\t\t|  3. Exit                                  |\n";           // Option to exit the system
        cout << "\t\t\t\t==============================================\n";
        cout << "\n\t\t\t\t| Enter your choice: ";

        int mainChoice;
        cin >> mainChoice; // Get user's choice
        pressToContinue(); // Prompt to continue
        if (mainChoice == 1) { // If admin login selected
            string id, pass;
            system("cls"); // Clear the screen
            cout << "\n\t\t\t\t| Enter Admin ID: ";
            cin >> id; // Get admin ID
            cout << "\n\t\t\t\t| Enter Password: ";
            cin >> pass; // Get admin password
            pressToContinue(); // Prompt to continue
            if (admin.login(id, pass)) { // If login is successful
                int adminChoice;
                do {
                    admin.displayMenu(); // Display admin menu
                    cout << "\n\t\t\t\t| Enter your choice: ";
                    cin >> adminChoice; // Get admin menu choice

                    switch (adminChoice) {
                    case 1: {
                        admin.viewMovies(movies, movieCount); // View available movies
                        pressToContinue(); // Prompt to continue
                        break;
                    }
                    case 2: {
                        cout << "\n\t\t\t\t| Exiting Admin Menu...\n"; // Exit admin menu
                        pressToContinue(); // Prompt to continue
                        break;
                    }
                    default: {
                        cout << "\n\t\t\t\t| Invalid choice!\n"; // Invalid menu choice
                        break;
                    }
                    }
                } while (adminChoice != 2); // Repeat until exit
            }
        } else if (mainChoice == 2) { // If customer login selected
            string username, pass;
            system("cls"); // Clear the screen
            cout << "\n\t\t\t\t| Enter Username: ";
            cin >> username; // Get customer username
            cout << "\n\t\t\t\t| Enter Password: ";
            cin >> pass; // Get customer password
            pressToContinue(); 

            Customer customer(username, pass); // Create customer object

            int customerChoice;
            do {
                customer.displayMenu(); // Display customer menu
                cout << "\n\t\t\t\t| Enter your choice: ";
                cin >> customerChoice; // Get customer menu choice

                switch (customerChoice) {
                case 1: {
                    customer.viewMovies(movies, movieCount); // View movies
                    pressToContinue(); // Prompt to continue
                    break;
                }
                case 2: {
                    customer.bookTicket(movies, movieCount, seatManager); // Book a ticket
                    pressToContinue(); // Prompt to continue
                    break;
                }
                case 3: {
                    cout << "\n\t\t\t\t| Exiting Customer Menu...\n"; // Exit customer menu
                    break;
                }
                default: {
                    cout << "\n\t\t\t\t| Invalid choice!\n"; // Invalid menu choice
                    break;
                }
                }
            } while (customerChoice != 3); // Repeat until exit
        }
        else if (mainChoice == 3) { // If exit selected
            cout << "\n\t\t\t\t| Exiting system...\n"; // Exit the system
            break;
        }
        else {
            cout << "\n\t\t\t\t| Invalid choice!\n"; // Invalid choice in main menu
        }
    }

    return 0; // End of the program
}

