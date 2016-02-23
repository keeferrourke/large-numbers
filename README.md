# large-numbers

#####Update 2016-02-23
This project is officially abandoned. I have no plans to ever update this thing again. All relevant cpp and hpp files have been uploaded here, so they may serve as reference for other developer's work; in particular young programmers.

##What is this?
This is a project that I started in my grade 11 computer science class in which I created some functions to deal with large number operations.
Feel free to use any of the code in this project as part of your projects, respecting the terms of the GNU Lesser General Public License v3.

##How do I use this?
This project is basically just a collection of functions inside of header files which do basic math on vectors of integers. You can make use of these header files by copying them to your project's working directory and including them with `#include "file_name.hpp"` in the preamble of your C++ source file.

Currently, there are working(?) functions for addition, subtraction, and multiplication of large numbers. These large numbers should be represented as vectors of integers.

##Why might this be useful?
While I can provide no guarantees that this code will actually be useful to you, you might want to use it if you need a simple way to represent numbers that are too large to be `long long` or `unsigned long long` variables.

##What can I expect from this?
In short, nothing really. But plans for future updates include adding an easy way to convert strings of digits to vectors (you won't need to code that yourself anymore!), the creation of a division function, a modulus function, and an exponentiation function.

Right now I'm cleaning up some of the ugly code that was in this project before, and working on some small optimisations and improvements to the overall quality of the code, though these are low priority as I have other class work/projects to attend to.

##DOES THIS EVEN WORK?
Maybe?? Results may vary. I know for a fact that these functions worked on my machine less than a year ago. Unfortunately when I wrote this originally I didn't really value the whole concept of *documentation*. So when I was making some changes and cleaning this up before I made the first commit, I was largely guessing at my own work. If you find a bug and want to help me fix it, I'd love you <3

##Can I contribute to this project?
Absolutely! If you feel like you can a) code this better than I have, b) do some stuff I haven't yet, or c) otherwise improve the overall quality of this project, then feel free to contact me at keefer.rourke@gmail.com, fork this thing, open an issue, submit a pull request, etc etc.

I also might need some help documenting this project properly, and making it generally easier to use. Let me know if you're interested in helping.

##Can I use this thing?
Go for it! This project is free/libre software and you can use it however you want to. You can run, copy, distribute, study, and modify/change this software as it fits your needs. It's even licensed appropriately under the LGPLv3 so you can include this code in proprietary applications as well (though I encourage you to use a more permissive license).

If you want, send me an email and let me know how/why you're using this project, and I'll check out yours! :)
