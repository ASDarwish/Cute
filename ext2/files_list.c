/*			-*- mode: Fundamental; -*-
 *
 * List of file paths for testing the file system driver ('UNIX path' to inode)
 * pathname translation code.  Put as much file pathes as you like here!
 *
 * You can build a comprehensive list by going to FS root, then typing:
 *	$ find -type f -o -type d | sed -e 's/^\.//' -e 's/^/\t"/' -e 's/$/",/'
 */

#include <kernel.h>
#include <tests.h>
#include <ext2.h>

#if	EXT2_TESTS || EXT2_SMP_TESTS || FILE_TESTS

struct path_translation ext2_files_list[] = {
	{.path = NULL, },		/* DO NOT REMOVE - End of List mark */
};

/*
 * All of these file paths should return EXT2_ROOT_INODE!
 */
const char *ext2_root_list[] = {
	"/", "//", "///", "////", "/////", "//////", "///////",
	"/.", "/./", "/.//", "/.//", "/.///", "/.////", "/./////",
	"/..", "/../", "/..//", "/..///", "/..////", "/../////",

	"/./.", "/././", "/././/", "/././/", "/.././//", "/././///",
	"/.//.", "/.//./", "/.//.//", "/.//.///", "/.//.////",
	"/.///.", "/.///./", "/.///.//", "/.///.///", "/.///.////",
	"/./..", "/./../", "/./..//", "/./..///", "/./..////",
	"/.//..", "/.//../", "/.//..//", "/.//..///", "/.//..////",
	"/.///..", "/.///../", "/.///..//", "/.///..///", "/.///..////",

	"/../.", "/.././", "/.././/", "/.././/", "/.././//", "/.././///",
	"/..//.", "/..//./", "/..//.//", "/..//.///", "/..//.////",
	"/..///.", "/..///./", "/..///.//", "/..///.///", "/..///.////",
	"/../..", "/../../", "/../..//", "/../..///", "/../..////",
	"/..//..", "/..//../", "/..//..//", "/..//..///", "/..//..////",
	"/..///..", "/..///../", "/..///..//", "/..///..///", "/..///..////",

	"/../../../../../../../../..", "/../../../../../../../../../",
	"/././././././././.", "/./././././././././", "/./././././././././/",
	"/.././/.././/.././/.././/.././/.././/.././/.././/.././/.././/../.",
	NULL,
};

#endif	/* EXT2_TESTS || FILE_TESTS */
