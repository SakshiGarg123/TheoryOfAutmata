Assignment 7

Huntington's disease diagnostic. Huntington's disease (HD) is an inherited and fatal neurological disorder. Although there is currently no cure, in 1993 scientists discovered a very accurate genetic test. The gene that causes Huntington's disease is located on the short arm of chromosome 4, and it has a variable number of repeats of the CAG trinucleotide. These "stuttering" repeats lead to an excess in the amount of the amino acid glutamine in the protein huntingtin. The normal range of CAG repeats is between 10 and 35. Individuals with HD may have between 36 and 180 repeats. Doctors can use a simple PCR-based DNA test, count the number of repeats, and inform patients whether they are at risk.
 Repeats 	Diagnosis 
 0 - 9	 	not human
 10 - 35	normal
 36 - 39	high risk
 40 - 180	Huntington's disease
 181 - ∞	not human

Write a program following state machine (deterministic finite automata) to read in a human DNA sequence from standard input and identify whether the patient is at risk for HD by determining the maximum number of CAG repeats. Output the maximum number of repeats, and an appropriate medical diagnosis based on the table above. The data file format will consist of a sequence of the letters A, C, G, and T, along with arbitrary amounts of whitespace separating the letters. For full credit, your program should be able to identify CAG repeats that span multiple lines.

For example, the following sequence has a CAG repeat of size 4.

TTTTTTTTTTTTTTTTTTTTTTTTTTTTCAGCAGCAG
CAGTTTCAGCAGTTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT

Here is a sample run of your program:
% executable_file_name < test1.txt
max number of CAG repeats = 4
not human
