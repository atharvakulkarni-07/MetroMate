// Including the necessary header files.
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<limits>

using namespace std;

// Defining the station class

class Station {

    public: string name;

    // constructor:
    Station(string stationName) {
        name = stationName;
    }
};


class Graph {
    public:
    unordered_map < Station * ,vector < pair < Station * ,double > > >adjList;

     void addStation(Station * station) {
        adjList[station] = vector < pair < Station * , double > > ();
    }

    void addConnection(Station * src, Station * dest, double distance) {
        adjList[src].push_back(make_pair(dest, distance));
        adjList[dest].push_back(make_pair(src, distance));
    }

    // Here both way commuting is allowed;

    vector < pair < Station * ,
    double > > getConnections(Station * station)
    {
        return adjList[station];
    }
};


unordered_map < Station * , double > dijkstra(Graph & graph, Station * start) {
    unordered_map < Station * , double > distances;
    // Initialize distances to infinity for all stations
    for (const auto & pair: graph.adjList) {
        distances[pair.first] = numeric_limits < double > ::infinity();
    }
    distances[start] = 0; // Distance to the start station is 0

    // Create a priority queue to store stations and their distances
    priority_queue < pair < double, Station * > , vector < pair < double, Station * > > , greater < pair < double, Station * > > > pq;
    pq.push(make_pair(0, start)); // Push the starting station with distance 0

    while (!pq.empty()) {
        // Get the station with the smallest distance
        Station * current = pq.top().second;
        double currentDist = pq.top().first;
        pq.pop();

        // Iterate through neighbors of the current station
        vector < pair < Station * , double > > neighbors = graph.getConnections(current);
        for (size_t i = 0; i < neighbors.size(); ++i) {
            Station * neighbor = neighbors[i].first;
            double weight = neighbors[i].second;

            double newDist = currentDist + weight; // Calculate new distance
            // If the new distance is smaller, update it and push to the queue
            if (newDist < distances[neighbor]) {
                distances[neighbor] = newDist;
                pq.push(make_pair(newDist, neighbor));
            }
        }
    }

    return distances; // Return the map of shortest distances
}

double calculateFare(double distance, double farePerKm) {
    return distance * farePerKm; // Total fare calculation based on user-defined rate
}



int main() {
    Graph metroGraph;

    int numStations;
    cout << "Enter the number of stations: ";
    cin >> numStations;

    // Create stations based on user input
    vector<Station*> stations;
    for (int i = 0; i < numStations; ++i) {
        string stationName;
        cout << "Enter name of station " << (i + 1) << ": ";
        cin >> stationName;
        Station* newStation = new Station(stationName);
        metroGraph.addStation(newStation);
        stations.push_back(newStation);
    }

    int numConnections;
    cout << "Enter the number of connections: ";
    cin >> numConnections;

    // Create connections based on user input
    for (int i = 0; i < numConnections; ++i) {
        string station1, station2;
        double distance;
        cout << "Enter connection (station1 station2 distance): ";
        cin >> station1 >> station2 >> distance;

        // Find the corresponding Station objects
        Station* src = nullptr;
        Station* dest = nullptr;

        for (auto& station : stations) {
            if (station->name == station1) {
                src = station;
            }
            if (station->name == station2) {
                dest = station;
            }
        }

        if (src && dest) {
            metroGraph.addConnection(src, dest, distance);
        } else {
            cout << "One or both stations not found!" << endl;
        }
    }

    // Ask for fare per unit distance
    double farePerKm;
    cout << "Enter fare per kilometer: ";
    cin >> farePerKm;

    // User input for source and destination
    string sourceName, destName;
    
    cout << "Enter source station: ";
    cin >> sourceName; // Assume valid station names are used
    cout << "Enter destination station: ";
    cin >> destName;

    // Find shortest path using Dijkstra's algorithm
    auto distances = dijkstra(metroGraph, stations[0]); // Replace with actual source station

    // Output fare based on distance
    for (auto& station : stations) {
        if (station->name == destName) {
            if (distances[station] != numeric_limits<double>::infinity()) {
                double fare = calculateFare(distances[station], farePerKm); // Pass fare rate to calculation
                cout << "Fare from " << sourceName << " to " << destName << ": " 
                     << fare << " currency units" << endl;
                cout << "Distance: " << distances[station] << " km" << endl;
            } else {
                cout << "No route found from " << sourceName << " to " << destName 
                     << "." << endl;
            }
            break;
        }
    }

    // Clean up dynamically allocated memory
    for (auto& station : stations) {
        delete station;
    }

    return 0;
}