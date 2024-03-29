(function ($) {

$(document).ready(function()
{
  $("form#rooms-availability-filter-month-form select").change(function() {
    $("form#rooms-availability-filter-month-form").submit();
  });

  $('#edit-select-all').change(function() {
    if (this.options.selectedIndex == 1) {
      var table = $(this).closest('table')[0];
      $('input[id^="edit-rooms"]:not(:disabled)', table).attr('checked', true);

      jQuery.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + '?q=admin/rooms/select-all-pages-av',
        data: {'select-all': '0'},
      });
    }
    else if (this.options.selectedIndex == 2) {
      jQuery.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + '?q=admin/rooms/select-all-pages-av',
        data: {'select-all': '1'},
      });

      var table = $(this).closest('table')[0];
      $('input[id^="edit-rooms"]:not(:disabled)', table).attr('checked', true);
    }
    else if (this.options.selectedIndex == 3) {
      var table = $(this).closest('table')[0];
      $('input[id^="edit-rooms"]:not(:disabled)', table).attr('checked', false);

      jQuery.ajax({
        type: 'POST',
        url: Drupal.settings.basePath + '?q=admin/rooms/select-all-pages-av',
        data: {'select-all': '0'},
      });
    }
  });
});

Drupal.behaviors.rooms_availability = {
  attach: function(context) {

    // Current month is whatever comes through -1 since js counts months starting from 0
    currentmonth = parseInt(Drupal.settings.roomsUnitManagement.currentMonth)-1;
    currentyear = parseInt(Drupal.settings.roomsUnitManagement.currentYear);

    // The first month on the calendar
    month1 = currentmonth;
    year1 = currentyear;

    var calendars = new Array();
    var i = 0;
    for (i=0;i<Drupal.settings.roomsUnitManagement.roomsNumber;i++) {
      calendars[i] = new Array('#calendar' + i, month1, year1);
    }

    var c = 0;
    $.each(calendars, function(key, value) {
      // phpmonth is what we send via the url and need to add one since php handles
      // months starting from 1 not zero
      phpmonth = value[1]+1;

      var unit_id = Drupal.settings.roomsUnitManagement.roomsId[c];

      $(value[0]).once().fullCalendar({
        ignoreTimezone:false,
        editable:false,
        selectable: true,
        defaultView:'singleRowMonth',
        month:value[1],
        year:value[2],
        header:{
          left: 'title',
          center: '',
          right: ''
        },
        events: Drupal.settings.basePath + '?q=rooms/units/unit/' + Drupal.settings.roomsUnitManagement.roomsId[c] + '/availability/json/' + value[2] + '/' + phpmonth,
        select: function(start, end, allDay) {
          var sd = Math.round(Date.parse(start)/1000);
          var ed = Math.round(Date.parse(end)/1000);
          // This fires up Colobox to display info relevant to event from Drupal
          if ($.colorbox) {
            var url = Drupal.settings.basePath + '?q=admin/rooms/units/unit/' + unit_id + '/event/-2/' + sd + '/' + ed;
            $.colorbox({
              href: url,
              opacity: 0.7,
              width: 400,
              height: 400,
              onClosed:function(){
                $(value[0]).fullCalendar('refetchEvents');
              }
            });
          }

          $(value[0]).fullCalendar('unselect');
        }

      });

      c++;
    });

    // Resize takes care of some quirks on occasion
    $(window).resize();

  }
};
})(jQuery);
