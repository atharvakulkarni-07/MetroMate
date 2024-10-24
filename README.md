# MetroMate: Smart Route Planner and Fare Calculator

**MetroMate** is a C++ console-based application that provides an intuitive way to plan metro routes and calculate fares based on the distance traveled. It uses efficient graph algorithms (such as Dijkstra's) to find the shortest path between metro stations and calculates the fare based on user-defined rates.

## 🚀 Features

- **Metro Route Planning**: Users can add multiple stations and connections between them, forming a metro network. The program calculates the shortest route between any two stations.
- **Fare Calculation**: Based on the distance between two stations, the program calculates the fare using a customizable fare-per-kilometer rate.
- **Dynamic Network Setup**: Users can input the number of stations and connections, allowing flexibility in building metro networks of any size.
- **Shortest Path Finder**: The app uses Dijkstra's algorithm to find the most efficient route between stations.
- **Distance Display**: Displays the total distance of the journey along with the calculated fare.

## 🌟 Why MetroMate?

Planning metro routes manually can be time-consuming, especially in a large network. MetroMate simplifies this by allowing users to dynamically create metro networks, efficiently find the shortest paths, and instantly calculate fares. It’s an ideal tool for city planners, developers, and anyone interested in learning about shortest path algorithms or fare calculation systems.

## 📖 How It Works

1. **Add Stations**: Input the number of stations in the metro network.
2. **Set Connections**: Specify connections between stations and the distances between them.
3. **Fare Setup**: Enter the fare-per-kilometer rate for the system.
4. **Find Route & Fare**: Choose your source and destination stations, and the app will compute the shortest route and fare based on the distance.

## 🛠️ Technologies Used

- **C++**: Core programming language used for building the route planner and fare calculator.
- **Dijkstra's Algorithm**: For finding the shortest path between two metro stations.
- **STL (Standard Template Library)**: Utilized for data structures like `unordered_map`, `vector`, and `priority_queue` for efficient processing.
