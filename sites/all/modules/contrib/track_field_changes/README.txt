-----------------------------------------------------------------------------
ABOUT Track Field Changes
-----------------------------------------------------------------------------
The Track Field Changes enable to track/audit easily all the fields updates.

The module does not use the default Drupal Versioning system. 
The system will save the time, the user, 
the value before and after each modification on a field.

-----------------------------------------------------------------------------
CURRENT FEATURES
-----------------------------------------------------------------------------

    Select which content type need to be audited
    Select which fields need to be audited
    Integration with view

Supported fields :

    Title
    Body
    Boolean
    Date
    Date ISO
    Date Unix
    Decimal
    File (Limited support)
    Email
    Float
    Image (Limited support)
    Interger
    Link
    List (float)
    List (integer)
    List (text)
    Lon Text
    Term reference
    Text

-----------------------------------------------------------------------------
INSTALLATION
-----------------------------------------------------------------------------

1. Download and Enable the module

-----------------------------------------------------------------------------
USAGE
-----------------------------------------------------------------------------

1. Set up the fields and content type you would like to audit:
/admin/config/system/track_field_changes

2. Create a view and add the 'Track Field Changes' fields.

-----------------------------------------------------------------------------
Future roadmap
-----------------------------------------------------------------------------

    Enable track changes on every entity (user,..)
