class Emitter {

  constructor() {
    this.eventsHandler = [];
  }

  subscribe(event, callback) {
    let subscription = this.eventsHandler.filter(item => item.eventName === event)[0];
    if (subscription) {
      subscription.callbacks.push(callback);
    }
    else {
      subscription = {
        eventName: event,
        callbacks: [],
        release: function () {
          while (this.callbacks.length) {
            this.callbacks.pop();
          }
        }
      }
      subscription.callbacks.push(callback);
      this.eventsHandler.push(subscription);
    }
    return subscription;
  }

  emit(event, first_value, second_value) {
    for (let e of this.eventsHandler) {
      if (e.eventName === event) {
        for (let i = 0; i < e.callbacks.length; i++) {
          e.callbacks[i](first_value, second_value);
        }
      }
    }
  }
};

const emitter = new Emitter();

const test = function (a, b) {
  console.log(a, b);
};

const sub = emitter.subscribe("event_name", test);

emitter.emit("event_name", "first_value", "second_value");

sub.release();
