var app = angular.module('app', ['firebase']);

app.controller("ctrl", function($scope, $firebase) {
    var firebaseRef = new Firebase(
      // Replace this fictional URL with your own
      "https://johnny-fiv-sandbox.firebaseio.com/"
    );
    // create an AngularFire ref to the data
    var sync = $firebase(firebaseRef);

    // pull the data into a local model
    var syncObject = sync.$asObject();

    // sync the object with three-way data binding
    syncObject.$bindTo($scope, "data");
});
