/*  =========================================================================
    defs - Defines constants

    Copyright (C) 2014 - 2015 Eaton                                        
                                                                           
    This program is free software; you can redistribute it and/or modify   
    it under the terms of the GNU General Public License as published by   
    the Free Software Foundation; either version 2 of the License, or      
    (at your option) any later version.                                    
                                                                           
    This program is distributed in the hope that it will be useful,        
    but WITHOUT ANY WARRANTY; without even the implied warranty of         
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          
    GNU General Public License for more details.                           
                                                                           
    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.            
    =========================================================================
*/

#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED



//TODO: fix that better - this will work until we'll don't touch the initdb.sql
#define UI_PROPERTIES_CLIENT_ID 5
#define DUMMY_DEVICE_ID 1

/**
 * \brief Backward compatibility macro
 *
 * BIOS_ERROR_DB is long and contains BIOS which is temporal name and should be
 * replaced with something better, but to get stuff working in the meantime,
 * let's use compatibility macro.
 *
 */
#define BIOS_ERROR_DB DB_ERR

//! Possible error types
enum errtypes {
    //! First error should be UNKNOWN as it maps to zero and zero is weird
    UNKNOWN_ERR,
    DB_ERR,
    BAD_INPUT,
    INTERNAL_ERR,
    LICENSING_ERR,
};

//! Constants for database errors
enum db_err_nos {
    //! First error should be UNKNOWN as it maps to zero and zero is weird
    DB_ERROR_UNKNOWN,
    DB_ERROR_INTERNAL,
    // Probably should be removed at some point and replaced with bad_input_err
    DB_ERROR_BADINPUT,
    DB_ERROR_NOTFOUND,
    DB_ERROR_NOTIMPLEMENTED,
    DB_ERROR_DBCORRUPTED,
    DB_ERROR_NOTHINGINSERTED,
    DB_ERROR_DELETEFAIL,
    DB_ERROR_CANTCONNECT,
};

//! Constants for bad input type of error
enum bad_input_err {
    //! First error should be UNKNOWN as it maps to zero and zero is weird
    BAD_INPUT_UNKNOWN,
    BAD_INPUT_WRONG_INPUT,
    BAD_INPUT_OUT_OF_BOUNDS,
};

//! Constants for internal errors
enum internal_err {
    //! First error should be UNKNOWN as it maps to zero and zero is weird
    INTERNAL_UNKNOWN,
    INTERNAL_NOT_IMPLEMENTED
};

//! Constants for licensing-related errors
enum licensing_err {
    LICENSING_POWER_DEVICES_COUNT_REACHED,
    LICENSING_GLOBAL_CONFIGURABILITY_DISABLED
};


// TODO: Make the following 5 values configurable
#define NUT_MEASUREMENT_REPEAT_AFTER    300     //!< (once in 5 minutes now (300s))
#define NUT_INVENTORY_REPEAT_AFTER      3600    //!< (every hour now (3600s))
#define NUT_POLLING_INTERVAL            5000    //!< (check with upsd ever 5s)

// Note !!! If you change this value you have to change the following tests as well: TODO
#define AGENT_NUT_REPEAT_INTERVAL_SEC       NUT_MEASUREMENT_REPEAT_AFTER     //<! TODO 
#define AGENT_NUT_SAMPLING_INTERVAL_SEC     5   //!< TODO: We might not need this anymore

#define KEY_REPEAT "repeat"
#define KEY_STATUS "status"
#define KEY_CONTENT_TYPE "content-type"
#define PREFIX_X "x-"
#define OK      "ok"
#define ERROR   "error"
#define YES     "yes"
#define NO      "no"
#define KEY_ADD_INFO      "add_info"
#define KEY_AFFECTED_ROWS "affected_rows"
#define KEY_ERROR_TYPE     "error_type"
#define KEY_ERROR_SUBTYPE  "error_subtype"
#define KEY_ERROR_MSG      "error_msg"
#define KEY_ROWID          "rowid"

// asset_extra message
#define KEY_ASSET_TYPE_ID   "__type_id"
#define KEY_ASSET_SUBTYPE_ID   "__subtype_id"
#define KEY_ASSET_PARENT_ID "__parent_id"
#define KEY_ASSET_PRIORITY  "__priority"
#define KEY_ASSET_STATUS    "__status"
#define KEY_ASSET_NAME      "__name"
#define KEY_OPERATION       "__operation"

// agent names
#define FTY_EMAIL_ADDRESS "fty-email"

//static const std::string url = "sqlite:/work/core/tools/my1db.db";

// self test 
void
    defs_test (bool verbose);




#endif
