// Please see documentation at https://docs.microsoft.com/aspnet/core/client-side/bundling-and-minification
// for details on configuring this project to bundle and minify static web assets.

// Write your JavaScript code.


$(document).ready(function () {
    // Используем делегирование событий для новых .page-link
    $(document).on('click', '.page-link', function (e) {
        e.preventDefault();
        var url = $(this).attr('href');
        loadPage(url);
    });
});

function loadPage(url) {
    $.ajax({
        url: url,
        type: 'GET',
        success: function (data) {
            $('.partial-list-container').html(data);

            // Переназначаем слушатель после загрузки
            $(document).on('click', '.page-link', function (e) {
                e.preventDefault();
                var url = $(this).attr('href');
                loadPage(url);
            });
        }
    });
}



