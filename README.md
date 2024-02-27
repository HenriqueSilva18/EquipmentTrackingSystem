<h1>Equipment Tracking System</h1>


<h2>Description</h2>
This project is an equipment tracking system developed in C, tailored to efficiently track and oversee organizational assets. It enables 'administrators' to add, edit, remove, and search for equipment, categorize them by type and log maintenance operations. Additionally, the system generates reports on equipment status and maintenance history for each equipment. Users can search for specific equipment, view maintenance logs and request maintenance tasks if necessary.
<br />


<h2>Technologies Used</h2>
    <ul>
        <li>Programming Language: C</li>
        <li>Binary File Manipulation for Data Storage</li>
        <li>Dynamic Data Structures</li>
    </ul>

<h2>Features</h2>
    <ul>
        <li><strong>Equipment Management</strong>: Add, edit, remove, and search for equipments in the catalog.</li>
        <li><strong>User Management</strong>: Allow administrators to manage users, including creation, modification, and removal.</li>
        <li><strong>Category Management: </strong>Manage the categorization of equipment by status and category, enabling easy organization and retrieval.</li>
        <li><strong>Reports Generation</strong>: Generate analytical reports detailing equipment status, maintenance history, and user activity.</li>
        <li><strong>Data Persistence</strong>: Save and load data to/from binary files, maintaining data across sessions.</li>
    </ul>

<h2>Project Structure</h2>
    <ul>
        <li><code>main.c</code>: The entry point of the program, handling user interactions and overall flow.</li>
        <li><code>menus.h/c</code>: Modules for managing program menus</li>
        <li><code>input.h/c</code>: Modules for handling user's input and data validation.</li>
        <li><code>equipments.h/c</code>: Modules used to add, list, edit, remove and equipments.</li>
        <li><code>maintenances.h/c</code>: Modules for generating equipment's maintenances</li>
        <li><code>data.h/c</code>: Modules for binary file manipulation (reading and writing).</li>
        <li><code>users.h/c</code>: Modules for users to add, list, edit, remove users, besides assigning and returning equipments to the storage.</li>
        <li><code>utilities.h/c</code>: Modules for data structures used in the program.</li>
    </ul>
