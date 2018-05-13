# COP290
This is the course page for Design Practices in CS, for Semester II, 2017-2018, being taught by Subhashis Banerjee at the Department of Computer Science and Engineering, IIT Delhi.

Notice
Please click out the slots when you are not free for this course. Please clearly indicate your entry number (not name).
Objective(s) and plan
To get familiar with methods for doing (large?) projects in collaborative mode with special emphasis on software development.
We plan to cover: design, analysis and modeling; software requirement analysis and detailed specifications; design documentation; standard software development tools; testing; report.

The tools that we plan to cover include:


1. Standard Unix utilities.
2. Latex
3. gcc/g++ - the C pre-processor, header files, #defines; object files, linking, static and run-time libraries; Makefile.
4. using and creating libraries, ar and ranlib.
5. Object oriented style, classes, namespaces etc.
6. Multiprocessing and multithreading 
7. Version control.
8. Debugging and profiling tools.
9. macros and in-line code, loop transformations and un-rolling, speed-up issues.
10. Documentation tools like Doxygen.
11. auto-configuration, Makefile generation and porting issues.


The class will be required to do two common projects (in groups of two) and one open project (in groups of three or four). The students are encouraged to select a topic for their open project in consultation with faculty and/or Ph. D. and other senior students.
We may also do case studies of one or two large projects.

Resources
Common project I
Rough specification
Design and implement a software package for Engineering drawing. The package should have the following functionalities:


1. We should be able to interactively input or read from a file either i) an isometric drawing and a 3D object model or ii) projections on to any cross section.
2. Given the 3D model description we should be able to generate projections on to any cross section or cutting plane.
3. Given two or more projections we should be able to interactively recover the 3D description and produce an isometric drawing from any view direction.
Step I: Modeling and analysis
Work out a mathematical model for the problem. Figure out how many views are necessary? how many are sufficient? How can one compute projections given the 3D description? How can one compute the 3D description given one or more projections? What interactions are necessary?
