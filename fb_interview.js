class Emitter {

  constructor() {
    this.eventsHandler = new Map();
  }

  subscribe(event, callback) {
    let subscription = this.eventsHandler[event];
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
      this.eventsHandler[event] = subscription;
    }
    return subscription;
  }

  emit(event, first_value, second_value) {
    for (let i = 0; i < this.eventsHandler[event].callbacks.length; i++) {
      this.eventsHandler[event].callbacks[i](first_value, second_value);
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
