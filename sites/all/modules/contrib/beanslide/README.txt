Bean Slide creates a Bean block entity type with preconfigured fields for
images, text and links as rotating slides. As a block entity type, you can
create as many Bean Slide slideshows as you desire and place them using any
block placement method such as Drupal core blocks, Panels or Context.


REQUIREMENTS
------------

The following Drupal modules are required:
Image (Drupal core)
http://drupal.org/project/bean - Bean
http://drupal.org/project/field_collection - Field Collection
http://drupal.org/project/field_group - Field Group
http://drupal.org/project/libraries - Libraries API
http://drupal.org/project/link - Link
http://drupal.org/project/media - Media

One or more of the following javascript libraries is required for the
slideshow functionality:
http://jquery.malsup.com/cycle/download.html - jQuery Cycle
http://www.woothemes.com/flexslider/ - Flexslider
http://vegas.jaysalvat.com - jQuery Vegas
http://responsive-slides.viljamis.com - ResponsiveSlides


INSTALLATION
------------

1. Download one or more of the javascript libraries and place them
   into sites/all/libraries.
2. Download and enable Bean Slide and the required Drupal modules.
3. Go to admin/content/blocks and click Add Block" at the top of
   the page.
4. Create your Bean Slide!
5. Go to admin/structure/block and place your Bean Slide. You may also use an
   alternative block placement system like Context or Panels.


CONFIGURATION OPTIONS
---------------------

- Label: The label is used to identify your Bean Slide in the administrative
  interface.
- View Mode: Beans may have various view modes, however the "Default"
  mode should work best for nearly all uses.
- Title: The title of your Bean Slide block.
- Slides: The combination of an image, headline text, teaser content and link
  that will comprise a slide.
- Slideshow plugin: The javascript library to use for slide transitions.
  Changing the plugin may enable or disable additional settings.
- Image style: The Drupal core image style to apply to images.
- Transition duration: The time in milliseconds that it takes for each
  transition (e.g. fading into the next slide).
- Timeout: The time in milliseconds that each slide is shown before
  transitioning to the next slide.
- Pager: Setting this will provide a control to allow users to manually
  select slides.
- Navigation Controls: Setting this will provide the user controls to manually
  advance slides.
- Clickable caption: By default, a slide's link title will display as a
  clickable hyperlink. Checking this option will make the entire
  caption clickable.
- Include default CSS: Checking this will include some rudimentary CSS to
  style slides.
