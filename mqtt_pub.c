#include <stdio.h>
#include <mosquitto.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int rc;
	struct mosquitto *mosq;
	char target[20];

	mosquitto_lib_init();

	mosq = mosquitto_new("publisher-test", true, NULL);

	rc = mosquitto_connect(mosq, "localhost", 1883, 60);
	if (rc != 0)
	{
		printf("Client could not connect to broker! Error Code: %d\n", rc);
		mosquitto_destroy(mosq);
		return -1;
	}
	printf("We are now connected to the broker!\n");

	sprintf(target, "%s:%s:%s", argv[1], argv[2], argv[3]);

	mosquitto_publish(mosq, NULL, "control", strlen(target), target, 0, false);

	mosquitto_disconnect(mosq);
	mosquitto_destroy(mosq);

	mosquitto_lib_cleanup();

	printf("developerA modified1");
	printf("developerA modified2");

	printf("release v1.0 commit 1");

	printf("developerB modified1");
	printf("developerB modified2");

	prinf("developerA modified3");
	printf("developerA modified4");

	return 0;
}
