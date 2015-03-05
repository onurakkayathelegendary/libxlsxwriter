/*
 * Tests for the lib_xlsx_writer library.
 *
 * Copyright 2014, John McNamara, jmcnamara@cpan.org
 *
 */

#include "../ctest.h"
#include "../helper.h"

#include "xlsxwriter/worksheet.h"

// Test the _write_sheet_view() function.
CTEST(worksheet, write_sheet_view) {

    char* got;
    char exp[] = "<sheetView tabSelected=\"1\" workbookViewId=\"0\"/>";
    FILE* testfile = tmpfile();

    lxw_worksheet *worksheet = _new_worksheet(NULL);
    worksheet->file = testfile;
    worksheet_select(worksheet);

    _worksheet_write_sheet_view(worksheet);

    RUN_XLSX_STREQ(exp, got);

    _free_worksheet(worksheet);
}

