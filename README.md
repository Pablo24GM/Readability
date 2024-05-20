# Readability

In many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most appropriate. However, so it happens that there is an algorithm that could likely figure that out too.

In this little repo coded in C, I implemented a program that calculates the approximate grade level needed to comprehend some text. The program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), the program will output “Grade 16+” instead of giving the exact index number. If the grade level is less than 1, the program will output “Before Grade 1”.

## The Coleman-Liau Index

Therefore, in order to figure this out, what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too.

Several “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula goes as follows...

index = 0.0588 * L - 0.296 * S - 15.8

Where "L" is the average number of letters per 100 words in the text, and "S" is the average number of sentences per 100 words in the text.
