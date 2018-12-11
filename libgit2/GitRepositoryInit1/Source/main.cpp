/*
    Copyright (c) 2015 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include <git2.h>
#include <iostream>

int main(int argc, char* argv[])
{
    // Initialize the library
    int n = git_libgit2_init();
    std::cout << "git_libgit2_init: " << n << std::endl;

    // Initialize a new repository called Libgit2EmptyRepo1.
    // The git_repository_init creates the repository on the filesystem
    // and returns a corresponding git_repository instance
    // to interact with the repository.
    git_repository* repo = 0;
    int err = git_repository_init(&repo, "Libgit2EmptyRepo1", 0);
    if (err == 0)
    {
        std::cout << "Repository initialized successfully" << std::endl;

        git_repository_free(repo);
    }
    else
    {
        std::cout << "Error: git_repository_init failed" << std::endl;
    }

    // git_libgit2_shutdown should be called
    // once for every call to git_libgit2_init
    n = git_libgit2_shutdown();
    std::cout << "git_libgit2_shutdown: " << n << std::endl;

    return 0;
}
