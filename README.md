# Movie Ticketing System

## Description
This project is a command-line based movie ticketing system implemented in C++. It allows both admin and customer users to interact with the system. Admin users can view all available movies, while customer users can view movies and book tickets.

## Features
- **Admin Login**: Admin users can log in and view all available movies.
- **Customer Login**: Customers can log in, view movies, and book tickets.
- **Ticket Booking**: Customers can book a ticket for a specific movie and seat.
- **Seat Management**: The system manages the availability of seats for each movie.


## Usage
1. **Admin Login**
    - Username: `admin`
    - Password: `admin123`
    - After logging in, the admin can view all available movies.

2. **Customer Login**
    - Customers can log in with any username and password.
    - After logging in, customers can view movies and book tickets.

3. **Booking a Ticket**
    - Customers can select a movie and an available seat to book a ticket.
    - The system will display the ticket details after successful booking.

## Code Overview
### Classes
- **User**: Base class for admin and customer users, handles login and menu display.
- **Admin**: Inherits from `User`, has functionality to view all movies.
- **Customer**: Inherits from `User`, can view movies and book tickets.
- **Ticket**: Manages ticket details and generation of ticket IDs.
- **Seat**: Manages seat availability and booking.

### Main Functions
- **main**: Entry point of the program, handles user interactions and displays the main menu.
- **pressToContinue**: Utility function to pause the program until the user presses Enter.

## Example Movies
The system comes with a predefined list of movies:
1. The Shawshank Redemption | Drama | 142 mins | 14/05/2023 | 19:00 | $12.50
2. The Dark Knight | Action | 152 mins | 15/05/2023 | 21:00 | $15.00
3. Inception | Sci-Fi | 148 mins | 16/05/2023 | 20:00 | $14.00
4. Pulp Fiction | Crime | 154 mins | 17/05/2023 | 22:00 | $13.00
5. The Godfather | Drama | 175 mins | 18/05/2023 | 18:00 | $16.00
6. Forrest Gump | Comedy | 142 mins | 19/05/2023 | 20:30 | $11.50
7. The Matrix | Sci-Fi | 136 mins | 20/05/2023 | 21:00 | $12.00
8. Avengers: Endgame | Action | 181 mins | 21/05/2023 | 19:30 | $18.00
9. Titanic | Romance | 195 mins | 22/05/2023 | 18:30 | $14.50
10. Joker | Thriller | 122 mins | 23/05/2023 | 20:00 | $12.00
