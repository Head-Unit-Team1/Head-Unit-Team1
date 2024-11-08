#include "mapController.h"

MapController::MapController(QObject *parent) : QObject(parent) {
    apiKey = "{YOUR API KEY}";
}

QString MapController::getGoogleMapHtml() const {
    return R"(
            <!DOCTYPE html>
            <html>
            <head>
            <meta charset="UTF-8">
            <title>Google Map API</title>
            <style type="text/css">
                *{
                    margin: 0px;
                    padding: 0px;
                }
                #map{
                    width: 440px;
                    height: 550px;
                }
            </style>
            <script src="http://maps.google.com/maps/api/js?key={YOUR API KEY}&region=kr"></script>
            </head>

            <body>
                <div id="map"></div>
                <button id="btn1">Change 1</button>
                <button id="btn2">Change 2</button>
                <button id="btn3">Road View</button>

                <script type="text/javascript">
                    var btn1 = document.getElementById("btn1");
                    var btn2 = document.getElementById("btn2");
                    var btn3 = document.getElementById("btn3");
                    btn1.addEventListener("click", changeMap1);
                    btn2.addEventListener("click", changeMap2);
                    btn3.addEventListener("click", changeMap3);

                    var map;
                    function initMap(){
                        var ll = {lat: 52.424427, lng: 10.792172};
                        map = new google.maps.Map(
                                document.getElementById("map"),
                                {zoom: 17, center: ll}
                                );
                        new google.maps.marker.AdvancedMarkerElement(
                            {position: ll, map: map, label: "current position"}
                        );
                    }
                    initMap();

                    function changeMap1(){
                        var ll = {lat:52.426744, lng: 10.777209};
                        map.panTo(ll);
                        map.setZoom(16);
                    }
                    function changeMap2(){
                        var ll = {lat:-40.339098, lng: 175.609729};
                        map = new google.maps.Map(
                                document.getElementById("map"),
                                {zoom:17, center: ll}
                                );
                    }
                    function changeMap3(){
                        window.open('pano.html','',width=300,height=300);
                    }
                </script>
            </body>
            </html>
        )";
}

QString MapController::getGoogleMapHtml_app() const {
    return R"(
            <!DOCTYPE html>
            <html>
            <head>
            <meta charset="UTF-8">
            <title>Google Map API</title>
            <style type="text/css">
                *{
                    margin: 0px;
                    padding: 0px;
                }
                #map{
                    width: 1024px;
                    height: 600px;
                }
            </style>
            <script src="http://maps.google.com/maps/api/js?key={YOUR API KEY}&region=kr"></script>
            </head>

            <body>
                <div id="map"></div>
                <button id="btn1">Change 1</button>
                <button id="btn2">Change 2</button>
                <button id="btn3">Road View</button>

                <script type="text/javascript">
                    var btn1 = document.getElementById("btn1");
                    var btn2 = document.getElementById("btn2");
                    var btn3 = document.getElementById("btn3");
                    btn1.addEventListener("click", changeMap1);
                    btn2.addEventListener("click", changeMap2);
                    btn3.addEventListener("click", changeMap3);

                    var map;
                    function initMap(){
                        var ll = {lat: 52.424427, lng: 10.792172};
                        map = new google.maps.Map(
                                document.getElementById("map"),
                                {zoom: 17, center: ll}
                                );
                        new google.maps.marker.AdvancedMarkerElement(
                            {position: ll, map: map, label: "current position"}
                        );
                    }
                    initMap();

                    function changeMap1(){
                        var ll = {lat:52.426744, lng: 10.777209};
                        map.panTo(ll);
                        map.setZoom(16);
                    }
                    function changeMap2(){
                        var ll = {lat:-40.339098, lng: 175.609729};
                        map = new google.maps.Map(
                                document.getElementById("map"),
                                {zoom:17, center: ll}
                                );
                    }
                    function changeMap3(){
                        window.open('pano.html','',width=300,height=300);
                    }
                </script>
            </body>
            </html>
        )";
}
