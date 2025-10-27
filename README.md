# CS-300 Data Structures and Algorithms - Portfolio Repository

## Overview

This repository contains coursework from **CS-300: Data Structures and Algorithms** at Southern New Hampshire University. The course explored fundamental data structures and their implementation in C++, focusing on analyzing time and space complexity to select appropriate data structures for various problem-solving scenarios.

## Course Structure

This portfolio includes artifacts from the following modules:

- **Module 2**: Vector sorting and algorithms
- **Module 3**: Linked lists implementation
- **Module 4**: Hash tables and collision resolution
- **Module 5**: Binary search trees
- **Module 6**: Data structure analysis (Project One)
- **Module 7**: Course planner application (Project Two)

## Portfolio Artifacts

### Project One: Data Structure Analysis
Analysis of runtime and memory characteristics for various data structures including vectors, linked lists, hash tables, and binary search trees. This analysis demonstrates understanding of time and space complexity trade-offs in selecting appropriate data structures for different use cases.

### Project Two: Course Planner Application
A complete working C++ application that loads course information from a CSV file and provides functionality to display courses in alphanumeric order. The application uses a map data structure to efficiently store and retrieve course information, including prerequisites.

**Key Features:**
- Load course data from CSV file
- Display all courses in alphanumeric order
- Retrieve detailed information for specific courses including prerequisites
- User-friendly menu-driven interface

The source code for Project Two can be found in `Mod7/ProjectTwo.cpp`.

## Reflection

### What was the problem you were solving in the projects for this course?

Throughout the course, the primary problems we addressed were understanding how to efficiently store, retrieve, and manipulate data using different data structures. In Project One, I analyzed the theoretical performance characteristics of various data structures to understand when to use each one. Project Two required implementing a practical application that needed to efficiently handle course data with prerequisite relationships. The challenge was selecting the right data structure, which in this case, was a map to provide fast lookups while maintaining sorted order for display purposes.

### How did you approach the problem? Consider why data structures are important to understand.

My approach began with analyzing the problem requirements. For each project, I first identified the key operations that would be performed most frequently - searches, insertions, or sorting. This analysis guided me toward understanding why different data structures matter. Data structures are critical because they directly impact both the performance and maintainability of software. For example, choosing a hash table for O(1) lookups versus a binary search tree for O(log n) lookups isn't just a technical detail - it can mean the difference between a responsive application and one that becomes unusable with large datasets. Understanding these trade-offs enables informed decisions that balance performance, memory usage, and code complexity.

### How did you overcome any roadblocks you encountered while going through the activities or project?

One significant challenge was grasping the internal mechanics of data structures like hash tables and binary trees. Initially, I struggled with understanding how hash collision resolution works and how tree rotations maintain balance in AVL trees. I overcame this by implementing the data structures from scratch in the earlier modules, which forced me to understand every detail. Debugging through pointer manipulation and memory management issues in C++ taught me the importance of careful memory handling. Another challenge was analyzing time complexity mathematically—I worked through numerous examples and practiced calculating Big-O notation until it became intuitive. When stuck, I would break down complex operations into their fundamental steps and analyze each one separately.

### How has your work on this project expanded your approach to designing software and developing programs?

This course fundamentally changed how I approach software design. Previously, I might have chosen the first data structure that came to mind or simply used arrays for everything. Now, I start by analyzing the problem's requirements and identifying the operations that will be performed most frequently. I consider factors like dataset size, read versus write frequencies, and memory constraints before selecting a data structure. This analytical approach extends beyond data structures - I now think more carefully about algorithmic choices and optimization opportunities. I've also learned to question my initial assumptions and validate my choices with complexity analysis, making me a more thoughtful and deliberate programmer.

### How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

Working with multiple data structures taught me the importance of clear code organization and encapsulation. In Project Two, I learned to separate concerns - data loading, display logic, and main program flow each have distinct responsibilities, making the code easier to modify. I now understand that writing maintainable code isn't just about making it work, but about making it understandable to future maintainers (including myself). The experience of implementing similar functionality across different data structures highlighted the importance of consistent naming conventions and logical code structure. Adaptability comes from writing code that isn't tightly coupled to specific implementations; for instance, the Course struct could easily be modified to include additional fields without breaking the rest of the program. I've learned that thoughtful organization and clear documentation are investments that pay dividends when requirements change or bugs need to be fixed.

## Conclusion

This course provided a solid foundation in data structures and algorithms that will be essential throughout my computer science career. The ability to analyze complexity and select appropriate data structures is fundamental to writing efficient, scalable software. The portfolio artifacts demonstrate both theoretical understanding and practical application of these concepts.
