function postMessageToDiscord(message) {

  message = message || "hi guys";

  var discordUrl = 'https://discord.com/api/webhooks/749986782887542877/xxLIbsgL1ylnsNRqvjHthifHZ6PjD1P3oay-1e7vAUPGV5kcPfQ9FOGwr0JK36ZRsdqb';
  var payload = JSON.stringify({content: message});

var params = {
  method: "POST",
  payload: payload,
  muteHttpExceptions: true,
  contentType: "application/json"
};

  var response = UrlFetchApp.fetch(discordUrl, params);

  Logger.log(response.getContentText());

}
